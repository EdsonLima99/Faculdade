/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dominio;

import dao.GenericDAO;
import dao.AcaiDAO;
import dao.ClienteDAO;
import dao.ConexaoHibernate;
import dao.ItemPedidoDAO;
import dao.PedidoDAO;
import dao.TamanhoAcaiDAO;
import dao.TamanhoDAO;
import gerenciador.FuncoesUteis;
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
    private PedidoDAO pedidoDAO;
    private ItemPedidoDAO itemPedidoDAO;

    public GerenciadorDominio() throws HibernateException {
        ConexaoHibernate.getSessionFactory();
        acaiDAO = new AcaiDAO();
        clienteDAO = new ClienteDAO();
        tamanhoAcaiDAO = new TamanhoAcaiDAO();
        tamanhoDAO = new TamanhoDAO();
        genericDAO = new GenericDAO();
        pedidoDAO = new PedidoDAO();
        itemPedidoDAO = new ItemPedidoDAO();
    }

    //INSERIR    
    public int inserirAcai(String nome, String volume, Double valor) throws HibernateException {
        Acai acai = acaiDAO.pesquisarNome(nome);
        if (acai == null) {
            acai = new Acai(nome);
            acaiDAO.inserir(acai);
        }
        Tamanho tamanho = tamanhoDAO.pesquisarTamanho(volume);

        TamanhoAcai tamanhoAcai = tamanhoAcaiDAO.buscarTamanhoAcaiPorAcaiETamanho(acai, tamanho);

        if (tamanhoAcai != null) {
            throw new RuntimeException("Já existe um registro de açai com esse tamanho.");
        } else {
            tamanhoAcai = new TamanhoAcai(acai, tamanho, valor);
        }

        genericDAO.inserir(tamanhoAcai);
        return tamanhoAcai.getId();
    }

    public int inserirCliente(String nome, char sexo, String endereco, int numero, String bairro, String cidade, String celular) throws HibernateException {
        Cliente cliente = new Cliente(nome, sexo, endereco, numero, bairro, cidade, celular);
        clienteDAO.inserir(cliente);
        return cliente.getId();
    }

    public int inserirPedido(Cliente cliente, char entrega, Double valorTotal, JTable tblPedidos) {
        Pedido pedido = new Pedido(new Date(), entrega, valorTotal, cliente);

        pedido.setValorTotal(valorTotal);
        genericDAO.inserir(pedido);

        int tam = tblPedidos.getRowCount();
        if (tam > 0) {
            for (int lin = 0; lin < tam; lin++) {
                Acai acai = (Acai) tblPedidos.getValueAt(lin, 1);
                int qtde = Integer.parseInt(tblPedidos.getValueAt(lin, 2).toString());
                Tamanho tamanho = (Tamanho) tblPedidos.getValueAt(lin, 3);
                int morango = FuncoesUteis.inteiro(tblPedidos.getValueAt(lin, 4).toString());
                int banana = FuncoesUteis.inteiro(tblPedidos.getValueAt(lin, 5).toString());
                int cereja = FuncoesUteis.inteiro(tblPedidos.getValueAt(lin, 6).toString());
                int leiteCondensado = FuncoesUteis.inteiro(tblPedidos.getValueAt(lin, 7).toString());
                int coberturaMorango = FuncoesUteis.inteiro(tblPedidos.getValueAt(lin, 8).toString());
                int coberturaChocolate = FuncoesUteis.inteiro(tblPedidos.getValueAt(lin, 9).toString());
                int leitePo = FuncoesUteis.inteiro(tblPedidos.getValueAt(lin, 10).toString());
                int pacoca = FuncoesUteis.inteiro(tblPedidos.getValueAt(lin, 11).toString());
                int chocoball = FuncoesUteis.inteiro(tblPedidos.getValueAt(lin, 12).toString());
                TamanhoAcai tamanhoAcai = tamanhoAcaiDAO.buscarTamanhoAcaiPorAcaiETamanho(acai, tamanho);

                ItemPedido item = new ItemPedido(qtde, morango, banana, cereja, leiteCondensado, coberturaMorango, coberturaChocolate, leitePo, pacoca, chocoball, pedido, tamanhoAcai);

                genericDAO.inserir(item);
            }
            return pedido.getId();
        } else {
            return -1;
        }
    }

    //ALTERAR
    public void alterarAcai(TamanhoAcai tamanhoAcai, Acai acai, String nome, String volume, Double valor) throws HibernateException {
        Acai acaiVerificado = acaiDAO.pesquisarNome(nome);

        if (acaiVerificado == null || acaiVerificado.getId() == acai.getId()) {
            acai.setNome(nome);
            Tamanho tamanho = tamanhoDAO.pesquisarTamanho(volume);

            TamanhoAcai tamanhoAcaiExistente = tamanhoAcaiDAO.buscarTamanhoAcaiPorAcaiETamanho(acai, tamanho);

            if (tamanhoAcaiExistente != null && tamanhoAcaiExistente.getId() != tamanhoAcai.getId()) {
                throw new RuntimeException("Já existe um registro de açai com esse tamanho.");
            }
            tamanhoAcai.setTamanho(tamanho);
            tamanhoAcai.setValor(valor);
            acaiDAO.alterar(acai);
            tamanhoAcaiDAO.alterar(tamanhoAcai);
        } else {
            throw new RuntimeException("Nome de açai já existente. Não é permitido alterar.");
        }
    }

    public void alterarCliente(Cliente cliente, String nome, char sexo, String endereco, int numero, String bairro, String cidade, String celular) throws HibernateException {
        cliente.setNome(nome);
        cliente.setSexo(sexo);
        cliente.setEndereco(endereco);
        cliente.setNumero(numero);
        cliente.setBairro(bairro);
        cliente.setCidade(cidade);
        cliente.setCelular(celular);
        clienteDAO.alterar(cliente);
    }

    public void alterarPedido(Pedido pedido) throws HibernateException {
        genericDAO.alterar(pedido);
    }

    public void alterarItemPedido(ItemPedido itemPedido) throws HibernateException {
        genericDAO.alterar(itemPedido);
    }

    //LISTAR
    public List listar(Class classe) throws HibernateException {
        return genericDAO.listar(classe);
    }

    public List listarTamanhoPorAcai(Acai acai) throws HibernateException {
        return tamanhoDAO.listarTamanhosAcai(acai);
    }

    public List listarPedidoPorCliente(Cliente cliente) throws HibernateException {
        return pedidoDAO.listarPedidoPorCliente(cliente);
    }

    public List listarItensPorPedido(Pedido pedido) throws HibernateException {
        return itemPedidoDAO.listarItemPorPedido(pedido);
    }

    public List<ItemPedido> listarItemPedidoPorTamanhoAcai(TamanhoAcai tamanhoAcai) throws HibernateException {
        return itemPedidoDAO.listarItemPedidoPorTamanhoAcai(tamanhoAcai);
    }

    //PESQUISAR
    public List<TamanhoAcai> pesquisarTamanhoAcai(int tipo, String pesquisar) throws IllegalArgumentException, HibernateException {
        List<TamanhoAcai> lista = null;

        switch (tipo) {
            case 0:
                lista = tamanhoAcaiDAO.pesquisarPorNome(pesquisar);
                break;
            case 1:
                lista = tamanhoAcaiDAO.pesquisarPorTamanho(pesquisar);
                break;
            case 2:
                if (!pesquisar.isEmpty()) {
                    try {
                        Double valor = Double.parseDouble(pesquisar);
                        lista = tamanhoAcaiDAO.pesquisarPorValor(valor);
                    } catch (NumberFormatException ex) {
                        throw new IllegalArgumentException("Valor de pesquisa inválido. Insira um número válido.", ex);
                    }
                } else {
                    throw new IllegalArgumentException("Campo de pesquisa vazio. Insira um valor para pesquisar.");
                }
                break;
            default:
                lista = acaiDAO.listar(Acai.class);
                break;
        }
        return lista;
    }

    public List<Cliente> pesquisarCliente(int tipo, String pesquisar) throws IllegalArgumentException, HibernateException {
        List<Cliente> lista = null;

        switch (tipo) {
            case 0:
                lista = clienteDAO.pesquisarPorNome(pesquisar);
                break;
            case 1:
                lista = clienteDAO.pesquisarPorBairro(pesquisar);
                break;
            case 2:
                lista = clienteDAO.pesquisarPorCidade(pesquisar);
                break;
            case 3:
                if (pesquisar.length() > 0) {
                    char sexo = pesquisar.charAt(0);
                    lista = clienteDAO.pesquisarPorSexo(sexo);
                } else {
                    throw new IllegalArgumentException("Campo de pesquisa vazio. Insira um valor para pesquisar.");
                }
                break;
        }
        return lista;
    }

    public TamanhoAcai buscarTamanhoAcaiPorAcaiETamanho(Acai acai, Tamanho tamanho) throws HibernateException {
        TamanhoAcai tamanhoAcai = null;
        tamanhoAcai = tamanhoAcaiDAO.buscarTamanhoAcaiPorAcaiETamanho(acai, tamanho);
        return tamanhoAcai;
    }

    //EXCLUIR
    public void excluir(Object objeto) throws HibernateException {
        genericDAO.excluir(objeto);
    }
}
