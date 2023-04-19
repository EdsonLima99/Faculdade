/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dominio;

import dao.AcaiDAO;
import dao.ClienteDAO;
import dao.ConexaoPostgres;
import gerenciador.FuncoesUteis;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import javax.swing.Icon;
import javax.swing.JTable;
import modelo.Acai;
import modelo.Cliente;

/**
 *
 * @author CONEXOS
 */
public class GerenciadorDominio {

    private AcaiDAO acaiDAO;
    private ClienteDAO clienteDAO;

    public GerenciadorDominio() throws ClassNotFoundException, SQLException {
        ConexaoPostgres.obterConexao();
        acaiDAO = new AcaiDAO();
        clienteDAO = new ClienteDAO();
    }

    public int inserirAcai(String nome, float valor) throws ClassNotFoundException, SQLException {
        Acai acai = new Acai(nome, valor);
        acaiDAO.inserir(acai);
        return acai.getId();
    }

    public void alterarAcai(int id, String nome, float valor) throws ClassNotFoundException, SQLException {
        Acai acai = new Acai(nome, valor);
        acai.setId(id);
        acaiDAO.alterar(acai);
    }

    public List<Acai> listarAcai() throws ClassNotFoundException, SQLException {
        return acaiDAO.listar();
    }

    public List<Acai> pesquisarAcai(int tipo, String pesquisar) throws ClassNotFoundException, SQLException {
        List<Acai> lista = null;

        switch (tipo) {
            case 0:
                lista = acaiDAO.pesquisarPorNome(pesquisar);
                break;
            case 1:
                lista = acaiDAO.pesquisarPorValor(pesquisar);
                break;
        }
        return lista;
    }

    public void excluir(Acai acai) throws ClassNotFoundException, SQLException {
        acaiDAO.excluir(acai);
    }

    public int inserirCliente(String nome, String cpf, Date dataNascimento, String cep, String endereco, int numero, String bairro, String referencia, String cidade, String telefone, String celular, String email, char sexo, Icon foto) throws ClassNotFoundException, SQLException {
        Cliente cliente = new Cliente(nome, cpf, dataNascimento, cep, endereco, numero, bairro, referencia, cidade, telefone, celular, email, sexo, FuncoesUteis.IconToBytes(foto));
        clienteDAO.inserir(cliente);
        return cliente.getId();
    }
}
