/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dominio;

import dao.GenericDAO;
import dao.AcaiDAO;
import dao.ClienteDAO;
import dao.ConexaoHibernate;
import dao.TamanhoAcaiDAO;
import dao.TamanhoDAO;
import java.util.Date;
import java.util.List;
import javax.swing.JTable;
import modelo.Acai;
import modelo.Cliente;
import modelo.ItemPedido;
import modelo.Pedido;
import modelo.Tamanho;
import modelo.TamanhoAcai;
import org.hibernate.HibernateException;

/**
 *
 * @author CONEXOS
 */
public class GerenciadorDominio {

    private GenericDAO genericDAO;
    private AcaiDAO acaiDAO;
    private ClienteDAO clienteDAO;
    private TamanhoAcaiDAO tamanhoAcaiDAO;
    private TamanhoDAO tamanhoDAO;

    public GerenciadorDominio() throws HibernateException {
        ConexaoHibernate.getSessionFactory();
        acaiDAO = new AcaiDAO();
        clienteDAO = new ClienteDAO();
        tamanhoAcaiDAO = new TamanhoAcaiDAO();
        tamanhoDAO = new TamanhoDAO();
        genericDAO = new GenericDAO();
    }

    public int inserirAcai(String nome, String volume, float valor) throws HibernateException {
        Acai acai = acaiDAO.pesquisarNome(nome);
        if (acai == null) {
            acai = new Acai(nome);
            acaiDAO.inserir(acai);
        }
        Tamanho tamanho = tamanhoDAO.pesquisarValor(volume);
        TamanhoAcai tamanhoAcai = new TamanhoAcai(acai, tamanho, valor);

        genericDAO.inserir(tamanhoAcai);
        return acai.getId();
    }

    public void alterarAcai(Acai acai, String nome) throws HibernateException {
        acai.setNome(nome);
        acaiDAO.alterar(acai);
    }

    public List listar(Class classe) throws HibernateException {
        return genericDAO.listar(classe);
    }

    public List<Acai> pesquisarAcai(int tipo, String pesquisar) throws HibernateException {
        List<Acai> lista = null;

        switch (tipo) {
            case 0:
                lista = acaiDAO.pesquisarPorNome(pesquisar);
                break;
            case 2:
                //lista = tamanhoAcaiDAO.pesquisarPorValor(Float.parseFloat(pesquisar));
                break;
            default:
                lista = acaiDAO.listar(Acai.class);
                break;
        }
        return lista;
    }

    public List listarAcaiDistinct() throws HibernateException {
        return acaiDAO.listarAcaiDistinct();
    }

    public List listarTamanhosAcai(String nome) throws HibernateException {
        return tamanhoDAO.listarTamanhosAcai(nome);
    }

    public float obterValorAcaiPorNomeETamanho(String nome, String tamanho) throws HibernateException {
        return tamanhoAcaiDAO.obterValorAcaiPorNomeETamanho(nome, tamanho);
    }

    public void excluir(Object objeto) throws HibernateException {
        genericDAO.excluir(objeto);
    }

    public int inserirCliente(String nome, char sexo, String endereco, int numero, String bairro, String cidade, String celular) throws HibernateException {
        Cliente cliente = new Cliente(nome, sexo, endereco, numero, bairro, cidade, celular);
        clienteDAO.inserir(cliente);
        return cliente.getId();
    }

    public void alterarCliente(Cliente cliente, String nome, char sexo, String endereco, int numero, String bairro, String cidade, String celular) throws HibernateException {
        cliente.setNome(nome);
        clienteDAO.alterar(cliente);
    }

    public void excluir(Cliente cliente) throws HibernateException {
        clienteDAO.excluir(cliente);
    }

    public List<Cliente> pesquisarCliente(int tipo, String pesquisar) throws HibernateException {
        List<Cliente> lista = null;

        switch (tipo) {
            case 0:
                lista = clienteDAO.pesquisarPorNome(pesquisar);
                break;
            case 1:
                lista = clienteDAO.pesquisarPorValor(pesquisar);
                break;
            default:
                lista = clienteDAO.listar(Cliente.class);
                break;
        }
        return lista;
    }

    public Float pesquisarTamanhoAcai(Class acai, Class tamanho) throws HibernateException {
        Float valor = Float.parseFloat("10");

//        texto = tamanhoAcaiDAO.pesquisarValor(acai, tamanho);
        return valor;
    }

    public TamanhoAcai listarTamanhoAcai(Float valor) throws HibernateException {
        TamanhoAcai tamanhoAcai = null;
        tamanhoAcai = tamanhoAcaiDAO.listarUnico(valor);
        return tamanhoAcai;
    }

    public TamanhoAcai listarTamanhoAcai(Acai acai, Tamanho tamanho) throws HibernateException {
        TamanhoAcai tamanhoAcai = null;
        tamanhoAcai = tamanhoAcaiDAO.listarUnico(acai, tamanho);
        return tamanhoAcai;
    }

    public int inserirPedido(Cliente cliente, char entrega, Float valorTotal, JTable tblPedidos) {
        Pedido pedido = new Pedido(new Date(), entrega, valorTotal, cliente);
        
        pedido.setValorTotal(valorTotal);
        genericDAO.inserir(pedido);
            
        int tam = tblPedidos.getRowCount();
        if (tam > 0) {
            for (int lin = 0; lin < tam; lin++) {
                Acai acai = acaiDAO.pesquisarNome(tblPedidos.getValueAt(lin, 1).toString());
                int qtde = Integer.parseInt(tblPedidos.getValueAt(lin, 2).toString());
                Tamanho tamanho = tamanhoDAO.pesquisarValor(tblPedidos.getValueAt(lin, 3).toString());
                int morango = inteiro(tblPedidos.getValueAt(lin, 4).toString());
                int banana = inteiro(tblPedidos.getValueAt(lin, 5).toString());
                int cereja = inteiro(tblPedidos.getValueAt(lin, 6).toString());
                int leiteCondensado = inteiro(tblPedidos.getValueAt(lin, 7).toString());
                int coberturaMorango = inteiro(tblPedidos.getValueAt(lin, 8).toString());
                int coberturaChocolate = inteiro(tblPedidos.getValueAt(lin, 9).toString());
                int leitePo = inteiro(tblPedidos.getValueAt(lin, 10).toString());
                int pacoca = inteiro(tblPedidos.getValueAt(lin, 11).toString());
                int chocoball = inteiro(tblPedidos.getValueAt(lin, 12).toString());
                TamanhoAcai tamanhoAcai = tamanhoAcaiDAO.listarUnico(acai, tamanho);

                ItemPedido item = new ItemPedido(qtde, morango, banana, cereja, leiteCondensado, coberturaMorango, coberturaChocolate, leitePo, pacoca, chocoball, pedido, tamanhoAcai);
                
                genericDAO.inserir(item);
            }
            return pedido.getId();
        } else {
            return -1;
        }
    }

    public int inteiro(String texto) {
        int inteiro = 0;
        if (texto.equals("Sim")) {
            inteiro = 1;
        } else {
            inteiro = 0;
        }
        return inteiro;
    }
}
