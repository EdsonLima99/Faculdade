/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package factorymethod;

/**
 *
 * @author CONEXOS
 */
public class FactoryMethod {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Rota rota = new RotaMeio();
        Classe classe = rota.criarClasse();
        classe.exibirInformacao();
        System.out.println();
        
        rota = new RotaBotAdc();
        classe = rota.criarClasse();
        classe.exibirInformacao();
        System.out.println();
        
        rota = new RotaBotSuporte();
        classe = rota.criarClasse();
        classe.exibirInformacao();
        System.out.println();
        
        rota = new RotaSelva();
        classe = rota.criarClasse();
        classe.exibirInformacao();
        System.out.println();
        
        rota = new RotaTop();
        classe = rota.criarClasse();
        classe.exibirInformacao();
        System.out.println();
    }
    
}
