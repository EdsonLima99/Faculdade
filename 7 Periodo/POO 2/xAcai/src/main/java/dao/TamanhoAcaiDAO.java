/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dao;

import java.util.List;
import javax.persistence.criteria.CriteriaBuilder;
import javax.persistence.criteria.CriteriaQuery;
import javax.persistence.criteria.Join;
import javax.persistence.criteria.Predicate;
import javax.persistence.criteria.Root;
import modelo.Acai;
import modelo.Tamanho;
import modelo.TamanhoAcai;
import org.hibernate.HibernateException;
import org.hibernate.Session;

/**
 *
 * @author CONEXOS
 */
public class TamanhoAcaiDAO extends GenericDAO {

    public TamanhoAcai listarUnico(Float valor) throws HibernateException {
        Session sessao = null;
        TamanhoAcai tamanhoAcai = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<TamanhoAcai> consulta = builder.createQuery(TamanhoAcai.class);
            Root<TamanhoAcai> root = consulta.from(TamanhoAcai.class);
            consulta.select(root).where(builder.equal(root.get("valor"), valor));

            tamanhoAcai = sessao.createQuery(consulta).uniqueResult();

            sessao.getTransaction().commit();
            sessao.close();
        } catch (HibernateException ex) {
            if (sessao != null) {
                sessao.getTransaction().rollback();
                sessao.close();
            }
            throw new HibernateException(ex);
        }
        return tamanhoAcai;
    }

    public TamanhoAcai listarUnico(Acai acai, Tamanho tamanho) throws HibernateException {
        Session sessao = null;
        TamanhoAcai tamanhoAcai = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<TamanhoAcai> consulta = builder.createQuery(TamanhoAcai.class);
            Root<TamanhoAcai> root = consulta.from(TamanhoAcai.class);
            consulta.select(root).where(builder.and((builder.equal(root.get("acai"), acai)), (builder.equal(root.get("tamanho"), tamanho))));

            tamanhoAcai = sessao.createQuery(consulta).uniqueResult();

            sessao.getTransaction().commit();
            sessao.close();
        } catch (HibernateException ex) {
            if (sessao != null) {
                sessao.getTransaction().rollback();
                sessao.close();
            }
            throw new HibernateException(ex);
        }
        return tamanhoAcai;
    }

    public List<TamanhoAcai> pesquisarPorValor(Float valor) throws HibernateException {
        Session sessao = null;
        List<TamanhoAcai> lista = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<TamanhoAcai> consulta = builder.createQuery(TamanhoAcai.class);
            Root<TamanhoAcai> root = consulta.from(TamanhoAcai.class);
            consulta.select(root).where(builder.equal(root.get("valor"), valor));

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

    public float obterValorAcaiPorNomeETamanho(String nome, String tamanho) throws HibernateException {
        Session sessao = null;
        float valor = 0;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<Float> consulta = builder.createQuery(Float.class);
            Root<TamanhoAcai> root = consulta.from(TamanhoAcai.class);
            Join<TamanhoAcai, Acai> joinAcai = root.join("acai");
            Join<TamanhoAcai, Tamanho> joinTamanho = root.join("tamanho");
            Predicate predicateNomeAcai = builder.equal(joinAcai.get("nome"), nome);
            Predicate predicateTamanhoAcai = builder.equal(joinTamanho.get("tamanho"), tamanho);
            consulta.select(root.get("valor")).where(builder.and(predicateNomeAcai, predicateTamanhoAcai));

            valor = sessao.createQuery(consulta).getSingleResult();

            sessao.getTransaction().commit();
            sessao.close();
        } catch (HibernateException ex) {
            if (sessao != null) {
                sessao.getTransaction().rollback();
                sessao.close();
            }
            throw new HibernateException(ex);
        }
        return valor;
    }
}
