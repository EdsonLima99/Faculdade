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
import modelo.Cliente;
import org.hibernate.HibernateException;
import org.hibernate.Session;

/**
 *
 * @author CONEXOS
 */
public class ClienteDAO extends GenericDAO {

    public List<Cliente> pesquisarPorNome(String nome) throws HibernateException {
        Session sessao = null;
        List<Cliente> lista = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<Cliente> consulta = builder.createQuery(Cliente.class);
            Root<Cliente> root = consulta.from(Cliente.class);

            Predicate predicado = builder.like(root.get("nome"), "%" + nome + "%");

            consulta.select(root).where(predicado).orderBy(builder.asc(root.get("nome")));

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

    public List<Cliente> pesquisarPorBairro(String bairro) throws HibernateException {
        Session sessao = null;
        List<Cliente> lista = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<Cliente> consulta = builder.createQuery(Cliente.class);
            Root<Cliente> root = consulta.from(Cliente.class);

            Predicate predicado = builder.like(root.get("bairro"), "%" + bairro + "%");

            consulta.select(root).where(predicado).orderBy(builder.asc(root.get("bairro")));

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

    public List<Cliente> pesquisarPorCidade(String cidade) throws HibernateException {
        Session sessao = null;
        List<Cliente> lista = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<Cliente> consulta = builder.createQuery(Cliente.class);
            Root<Cliente> root = consulta.from(Cliente.class);

            Predicate predicado = builder.like(root.get("cidade"), "%" + cidade + "%");

            consulta.select(root).where(predicado).orderBy(builder.asc(root.get("cidade")));

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

    public List<Cliente> pesquisarPorSexo(char sexo) throws HibernateException {
        Session sessao = null;
        List<Cliente> lista = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<Cliente> consulta = builder.createQuery(Cliente.class);
            Root<Cliente> root = consulta.from(Cliente.class);

            Predicate predicado = builder.equal(root.get("sexo"), Character.toUpperCase(sexo));

            consulta.select(root).where(predicado).orderBy(builder.asc(root.get("sexo")));

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
