/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gerenciador;

import dominio.GerenciadorDominio;
import interfaces.CadastroAcai;
import interfaces.CadastroCliente;
import interfaces.CadastroPedidos;
import interfaces.ClientesPorBairro;
import interfaces.ClientesPorNome;
import interfaces.FramePrincipal;
import interfaces.PesquisarAcai;
import interfaces.PesquisarCliente;
import java.awt.Frame;
import java.lang.reflect.InvocationTargetException;
import java.sql.SQLException;
import java.text.ParseException;
import java.util.Iterator;
import java.util.List;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import modelo.Acai;
import modelo.Cliente;
import modelo.Tamanho;
import modelo.TamanhoAcai;
import org.hibernate.HibernateException;

/**
 *
 * @author CONEXOS
 */
public class GerenciadorInterfaceGrafica {

    private FramePrincipal framePrincipal;
    private CadastroCliente cadastroCliente;
    private CadastroAcai cadastroAcai;
    private CadastroPedidos cadastroPedidos;
    private ClientesPorNome clientesPorNome;
    private ClientesPorBairro clientesPorBairro;
    private PesquisarAcai pesquisarAcai;
    private PesquisarCliente pesquisarCliente;

    GerenciadorDominio gerenciadorDominio;

    public GerenciadorInterfaceGrafica() {
        framePrincipal = null;
        cadastroCliente = null;
        cadastroAcai = null;
        cadastroPedidos = null;
        clientesPorNome = null;
        clientesPorBairro = null;
        pesquisarAcai = null;
        pesquisarCliente = null;

        try {
            gerenciadorDominio = new GerenciadorDominio();
        } catch (HibernateException ex) {
            JOptionPane.showMessageDialog(framePrincipal, ex);
            System.exit(1);
        }
    }

    public GerenciadorDominio getGerenciadorDominio() {
        return gerenciadorDominio;
    }

    // ABRIR JDIALOG
    private JDialog abrirJanela(java.awt.Frame parent, JDialog dlg, Class classe) {
        if (dlg == null) {
            try {
                dlg = (JDialog) classe.getConstructor(Frame.class, boolean.class, GerenciadorInterfaceGrafica.class).newInstance(parent, true, this);
            } catch (NoSuchMethodException | SecurityException | InstantiationException | IllegalAccessException | IllegalArgumentException | InvocationTargetException ex) {
                JOptionPane.showMessageDialog(parent, "Erro ao abrir a janela " + classe.getName());
            }
        }
        dlg.setVisible(true);
        return dlg;
    }

    public void abrirJanelaPrincipal() {
        if (framePrincipal == null) {
            framePrincipal = new FramePrincipal(this);
        }
        framePrincipal.setVisible(true);
    }

    public void abrirJanelaCadastroCliente() {
        abrirJanela(framePrincipal, cadastroCliente, CadastroCliente.class);
    }

    public void abrirJanelaCadastroAcai() {
        abrirJanela(framePrincipal, cadastroAcai, CadastroAcai.class);
    }

    public void abrirJanelaCadastroPedido() {
        abrirJanela(framePrincipal, cadastroPedidos, CadastroPedidos.class);
    }

    public void abrirJanelaConsultaClienteNome() {
        abrirJanela(framePrincipal, clientesPorNome, ClientesPorNome.class);
    }

    public void abrirJanelaConsultaClienteData() {
        abrirJanela(framePrincipal, clientesPorBairro, ClientesPorBairro.class);
    }
    
    public Acai abrirJanelaPesquisarAcai() {
        pesquisarAcai = (PesquisarAcai) abrirJanela(framePrincipal, pesquisarAcai, PesquisarAcai.class);
        return pesquisarAcai.getAcaiSelecionado();
    }
    
    public Cliente abrirJanelaPesquisarCliente() {
        pesquisarCliente = (PesquisarCliente) abrirJanela(framePrincipal, pesquisarCliente, PesquisarCliente.class);
        return pesquisarCliente.getClienteSelecionado();
    }

    public void carregarCombo(JComboBox combo, Class classe) {
        List lista;
        try {
            lista = gerenciadorDominio.listar(classe);
            combo.setModel(new DefaultComboBoxModel(lista.toArray()));
        } catch (HibernateException ex) {
            JOptionPane.showMessageDialog(framePrincipal, "Erro ao carregar. " + ex);
        }
    }
    
    public void carregarComboAcai(JComboBox combo) {
        List lista;
        try {
            lista = gerenciadorDominio.listarAcaiDistinct();
            combo.setModel(new DefaultComboBoxModel(lista.toArray()));
        } catch (HibernateException ex) {
            JOptionPane.showMessageDialog(framePrincipal, "Erro ao carregar. " + ex);
        }
    }
    
    public void carregarComboTamanho(JComboBox combo, String nome) {
        List lista;
        try {
            lista = gerenciadorDominio.listarTamanhosAcai(nome);
            combo.setModel(new DefaultComboBoxModel(lista.toArray()));
        } catch (HibernateException ex) {
            JOptionPane.showMessageDialog(framePrincipal, "Erro ao carregar. " + ex);
        }
    }
    
    public void carregarTabelaAcai(JTable tabela, Class classe){
        try {
            // TODO add your handling code here:
            List<TamanhoAcai> lista = getGerenciadorDominio().listar(classe);

            //Limpar a tabela
            ((DefaultTableModel) tabela.getModel()).setRowCount(0);

            for (TamanhoAcai tamanhoAcai : lista) {
                ((DefaultTableModel) tabela.getModel()).addRow(tamanhoAcai.toArray());
            }
        } catch (HibernateException | ParseException ex) {
            JOptionPane.showMessageDialog(framePrincipal, "Erro ao listar açaí. " + ex);
        }
    }
    
    public void carregarTabelaCliente(JTable tabela, Class classe){
        try {
            // TODO add your handling code here:
            List<Cliente> lista = getGerenciadorDominio().listar(classe);

            //Limpar a tabela
            ((DefaultTableModel) tabela.getModel()).setRowCount(0);

            for (Cliente cliente : lista) {
                ((DefaultTableModel) tabela.getModel()).addRow(cliente.toArray());
            }
        } catch (HibernateException | ParseException ex) {
            JOptionPane.showMessageDialog(framePrincipal, "Erro ao listar cliente. " + ex);
        }
    }
    
    public Float obterValorAcaiPorNomeETamanho(String nome, String tamanho) {
        Float valor = Float.parseFloat("0");
        try {
            valor = gerenciadorDominio.obterValorAcaiPorNomeETamanho(nome, tamanho);
        } catch (HibernateException ex) {
            JOptionPane.showMessageDialog(framePrincipal, "Erro ao carregar. " + ex);
        }
        return valor;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Windows".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(FramePrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(FramePrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(FramePrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(FramePrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        GerenciadorInterfaceGrafica gerenciadorInterfaceGrafica = new GerenciadorInterfaceGrafica();
        gerenciadorInterfaceGrafica.abrirJanelaPrincipal();
    }
}
