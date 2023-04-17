/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package factorymethod;

/**
 *
 * @author CONEXOS
 */
public class RotaSelva implements Rota {

    @Override
    public Classe criarClasse() {
        return new Assassino();
    }

}
