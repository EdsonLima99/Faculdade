/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dao;

import java.util.List;
import javax.persistence.criteria.CriteriaBuilder;
import javax.persistence.criteria.CriteriaQuery;
import javax.persistence.criteria.Root;
import modelo.Acai;
import org.hibernate.HibernateException;
import org.hibernate.Session;

/**
 *
 * @author CONEXOS
 */
public class AcaiDAO extends GenericDAO {

    public Acai pesquisarNome(String nome) throws HibernateException {
        Session sessao = null;
        Acai acai = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<Acai> consulta = builder.createQuery(Acai.class);
            Root<Acai> root = consulta.from(Acai.class);
            consulta.select(root).where(builder.equal(root.get("nome"), nome));

            acai = sessao.createQuery(consulta).uniqueResult();

            sessao.getTransaction().commit();
            sessao.close();
        } catch (HibernateException ex) {
            if (sessao != null) {
                sessao.getTransaction().rollback();
                sessao.close();
            }
            throw new HibernateException(ex);
        }
        return acai;
    }
    
    public List<Acai> pesquisarPorNome(String string) throws HibernateException {
        Session sessao = null;
        List<Acai> lista = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<Acai> consulta = builder.createQuery(Acai.class);
            Root<Acai> root = consulta.from(Acai.class);
            consulta.select(root).where(builder.like(root.get("nome"), "%" + string + "%"));

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

    public List<String> listarAcaiDistinct() throws HibernateException {
        Session sessao = null;
        List<String> lista = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<String> consulta = builder.createQuery(String.class);
            Root<Acai> root = consulta.from(Acai.class);
            consulta.select(root.get("nome")).distinct(true);
            
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
