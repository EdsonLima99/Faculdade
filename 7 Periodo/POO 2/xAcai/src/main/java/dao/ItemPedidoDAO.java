/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dao;

import java.util.List;
import javax.persistence.criteria.CriteriaBuilder;
import javax.persistence.criteria.CriteriaQuery;
import javax.persistence.criteria.Predicate;
import javax.persistence.criteria.Root;
import modelo.ItemPedido;
import modelo.Pedido;
import modelo.TamanhoAcai;
import org.hibernate.HibernateException;
import org.hibernate.Session;

/**
 *
 * @author CONEXOS
 */
public class ItemPedidoDAO extends GenericDAO {

    public List<ItemPedido> listarItemPorPedido(Pedido pedido) throws HibernateException {
        Session sessao = null;
        List<ItemPedido> lista = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<ItemPedido> consulta = builder.createQuery(ItemPedido.class);
            Root<ItemPedido> root = consulta.from(ItemPedido.class);
            Predicate predicate = builder.equal(root.get("pedido"), pedido);
            consulta.select(root).where(predicate);

            lista = sessao.createQuery(consulta).getResultList();

            sessao.getTransaction().commit();
        } catch (HibernateException ex) {
            if (sessao != null) {
                sessao.getTransaction().rollback();
            }
            throw new HibernateException(ex);
        } finally {
            if (sessao != null) {
                sessao.close();
            }
        }
        return lista;
    }

    public List<ItemPedido> listarItemPedidoPorTamanhoAcai(TamanhoAcai tamanhoAcai) throws HibernateException {
        Session sessao = null;
        List<ItemPedido> lista = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<ItemPedido> consulta = builder.createQuery(ItemPedido.class);
            Root<ItemPedido> root = consulta.from(ItemPedido.class);
            Predicate predicate = builder.equal(root.get("tamanhoAcai"), tamanhoAcai);
            consulta.select(root).where(predicate);

            lista = sessao.createQuery(consulta).getResultList();

            sessao.getTransaction().commit();
            sessao.close();
        } catch (HibernateException ex) {
            if (sessao != null) {
                sessao.getTransaction().rollback();
                sessao.close();
            }
            throw new HibernateException(ex);
        }
        return lista;
    }

}
