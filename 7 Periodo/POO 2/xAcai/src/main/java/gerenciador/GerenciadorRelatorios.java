/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gerenciador;

import java.io.InputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import javax.swing.JDialog;
import javax.swing.JOptionPane;
import net.sf.jasperreports.engine.JRException;
import net.sf.jasperreports.engine.JasperFillManager;
import net.sf.jasperreports.engine.JasperPrint;
import net.sf.jasperreports.engine.data.JRBeanCollectionDataSource;
import net.sf.jasperreports.engine.query.JRHibernateQueryExecuterFactory;
import net.sf.jasperreports.view.JasperViewer;

/**
 *
 * @author 1547816
 */
public class GerenciadorRelatorios {

    public void relComConexao() {
        try {
            // PASSO 1 - Caminho do relatório
            InputStream rel = getClass().getResourceAsStream("/RPCLIENTES.jasper");

            // PASSO 2 - Criar parâmetros de Pesquisa 
            Map parametros = new HashMap();

            // Conexao HIBERNATE
            parametros.put(JRHibernateQueryExecuterFactory.PARAMETER_HIBERNATE_SESSION,
                    dao.ConexaoHibernate.getSessionFactory().openSession());

            // PASSO 3 - Carregar o relatório com os dados
            // JRBeanCollectionDataSource dados = new JRBeanCollectionDataSource(lista);            
            JasperPrint print;
            print = JasperFillManager.fillReport(rel, parametros);

            if (!print.getPages().isEmpty()) {
                // PASSO 4 - Mostrat em uma JANELA

                // Cria o JasperViewer
                JasperViewer jrViewer = new JasperViewer(print, true);
                //jrViewer.setVisible(true);

                // Criar uma janela MODAL e colocar o JasperView dentro dela
                JDialog viewer = new JDialog(new javax.swing.JFrame(), "Visualização do Relatório", true);
                viewer.setSize(800, 600);
                viewer.setLocationRelativeTo(null);
                viewer.getContentPane().add(jrViewer.getContentPane());
                viewer.setVisible(true);
            } else {
                JOptionPane.showMessageDialog(null, "Relatório de clientes vazio.");
            }

        } catch (JRException erro) {
            JOptionPane.showMessageDialog(null, "ERRO ao abrir relatório de clientes. " + erro.getMessage());
        }
    }

    public void relComLista(List lista, String nome) {
        try {
            // PASSO 1 - Caminho do relatório
            String caminhoRelatorio = "/relatorios/" + nome;
            System.out.println("Caminho do relatório: " + caminhoRelatorio);
            InputStream rel = getClass().getResourceAsStream("/relatorios/" + nome);

            // COMPILAR
            // JasperReport rel = JasperCompileManager.compileReport(relArq);
            // PASSO 2 - Criar parâmetros de Pesquisa 
            Map parametros = new HashMap();

            if (!lista.isEmpty()) {
                // PASSO 3 - Carregar o relatório com os dados
                JRBeanCollectionDataSource dados = new JRBeanCollectionDataSource(lista);
                JasperPrint print;
                print = JasperFillManager.fillReport(rel, parametros, dados);

                if (!print.getPages().isEmpty()) {
                    // PASSO 4 - Mostrat em uma JANELA

                    // Cria o JasperViewer
                    JasperViewer jrViewer = new JasperViewer(print, true);
                    //jrViewer.setVisible(true);

                    // Criar uma janela MODAL e colocar o JasperView dentro dela
                    JDialog viewer = new JDialog(new javax.swing.JFrame(), "Visualização do Relatório", true);
                    viewer.setSize(800, 600);
                    viewer.setLocationRelativeTo(null);
                    viewer.getContentPane().add(jrViewer.getContentPane());
                    viewer.setVisible(true);

                } else {
                    JOptionPane.showMessageDialog(null, "Relatório vazio.");
                }
            } else {
                JOptionPane.showMessageDialog(null, "A lista de dados está vazia.");
            }

        } catch (JRException erro) {
            JOptionPane.showMessageDialog(null, "ERRO ao abrir relatório. " + erro.getMessage());

        }
    }
}
