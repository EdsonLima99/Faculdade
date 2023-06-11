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
public class TamanhoDAO extends GenericDAO {

    public Tamanho pesquisarTamanho(String volume) throws HibernateException {
        Session sessao = null;
        Tamanho tamanho = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<Tamanho> consulta = builder.createQuery(Tamanho.class);
            Root<Tamanho> root = consulta.from(Tamanho.class);
            consulta.select(root).where(builder.equal(root.get("tamanho"), volume));

            tamanho = sessao.createQuery(consulta).uniqueResult();

            sessao.getTransaction().commit();
            sessao.close();
        } catch (HibernateException ex) {
            if (sessao != null) {
                sessao.getTransaction().rollback();
                sessao.close();
            }
            throw new HibernateException(ex);
        }
        return tamanho;
    }

    public List<Tamanho> listarTamanhosAcai(Acai acai) throws HibernateException {
        Session sessao = null;
        List<Tamanho> lista = null;

        try {
            sessao = ConexaoHibernate.getSessionFactory().openSession();
            sessao.getTransaction().begin();

            CriteriaBuilder builder = sessao.getCriteriaBuilder();
            CriteriaQuery<Tamanho> consulta = builder.createQuery(Tamanho.class);
            Root<TamanhoAcai> root = consulta.from(TamanhoAcai.class);
            Join<TamanhoAcai, Acai> joinAcai = root.join("acai");
            Join<TamanhoAcai, Tamanho> joinTamanho = root.join("tamanho");
            Predicate predicate = builder.equal(joinAcai.get("nome"), acai.getNome());
            consulta.select(joinTamanho).where(predicate);

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
