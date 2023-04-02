/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package padrão.singleton;

/**
 *
 * @author CONEXOS
 */
public class PadrãoSingleton {
    private int valor;
    private static PadrãoSingleton instancia;
    
    private PadrãoSingleton(){
        valor = 0;
    }
    
    public static PadrãoSingleton getInstancia(){
        if(instancia == null){
            instancia = new PadrãoSingleton();
        }
        return instancia;
    }
    
    public void diminuirValor(int decrescimo){
        valor -= decrescimo;
    }
    
    public int getValor(){
        return valor;
    }
}
