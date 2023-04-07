/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gerenciador;

import interfaces.CadastroAcai;
import interfaces.CadastroCliente;
import interfaces.CadastroPedidos;
import interfaces.ClientesPorBairro;
import interfaces.ClientesPorNome;
import interfaces.FramePrincipal;
import java.awt.Frame;
import java.lang.reflect.InvocationTargetException;
import javax.swing.JDialog;
import javax.swing.JOptionPane;

/**
 *
 * @author CONEXOS
 */
public class GerenciadorInterfaceGrafica {

    private FramePrincipal framePrincipal = null;
    private CadastroCliente cadastroCliente = null;
    private CadastroAcai cadastroAcai = null;
    private CadastroPedidos cadastroPedidos = null;
    private ClientesPorNome clientesPorNome = null;
    private ClientesPorBairro clientesPorBairro = null;

    public GerenciadorInterfaceGrafica() {
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
