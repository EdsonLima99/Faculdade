/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dao;

import java.util.List;
import modelo.Cliente;
import modelo.Pedido;
import org.hibernate.Hibernate;
import org.hibernate.HibernateException;
import org.hibernate.Session;

/**
 *
 * @author CONEXOS
 */
public class ClienteDAO extends GenericDAO {
    
    // Carregar a lista de PEDIDOS de um CLIENTE
    public void carregarPedidos(Cliente cliente) {
        Session sessao = null;
        
        try {
                               
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.beginTransaction();

            // Verifica se a lista JÁ FOI CARREGADA
            if ( !Hibernate.isInitialized( cliente.getPedido() ) ) {
                
                // Carrega o PROXY para outro objeto
                Cliente clienteTemporario = sessao.get(Cliente.class, cliente.getId());

                // Carrega a lista de PEDIDOS
                List<Pedido> lista = clienteTemporario.getPedido();
                lista.size();

                // Atualiza a lista no OBJETO principal (parâmetro)
                cliente.setPedido(lista);
            }
            
            
            sessao.getTransaction().commit();              
            sessao.close();
        } catch( HibernateException erro) {
            if ( sessao != null ){
                sessao.getTransaction().rollback();
                sessao.close();
            }
            throw new HibernateException(erro);
        }
        
    }
    
    public List<Cliente> pesquisarPorNome(String string) throws HibernateException {
    return listar(Cliente.class);
    //return null;
    }

    public List<Cliente> pesquisarPorValor(String string) throws HibernateException {
        return null;
    }
}
