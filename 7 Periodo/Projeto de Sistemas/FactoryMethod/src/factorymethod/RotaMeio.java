/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package factorymethod;

/**
 *
 * @author CONEXOS
 */
public class RotaMeio implements Rota {

    @Override
    public Classe criarClasse() {
        return new Mago();
    }

}
