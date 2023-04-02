/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package padrão.singleton;

/**
 *
 * @author CONEXOS
 */
public class Desacumuladora {

    public static void outroMetodo(PadrãoSingleton ps){
        ps = PadrãoSingleton.getInstancia();
        ps.diminuirValor(50);
        ps.diminuirValor(10);
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        // PadrãoSingleton ps = new PadrãoSingleton();
        PadrãoSingleton ps = PadrãoSingleton.getInstancia();
        ps.diminuirValor(30);
        ps.diminuirValor(40);
        System.out.println("O valor é " + ps.getValor());
        
        Desacumuladora.outroMetodo(ps);
        System.out.println("O valor é " + ps.getValor());
    }
    
}
