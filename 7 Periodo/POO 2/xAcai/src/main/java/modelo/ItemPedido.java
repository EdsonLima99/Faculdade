/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import java.io.Serializable;
import java.text.ParseException;
import javax.persistence.Column;
import javax.persistence.EmbeddedId;
import javax.persistence.Entity;
import javax.persistence.Table;

/**
 *
 * @author CONEXOS
 */
@Entity
@Table(name = "ItemPedido", schema = "public")
public class ItemPedido implements Serializable {

    @EmbeddedId
    private ItemPedidoPK itemPedidoPK;
    
    @Column(name = "tamanho", nullable = false)
    private int tamanho;
    
    @Column(name = "morango", nullable = false)
    private int morango;
    
    @Column(name = "banana", nullable = false)
    private int banana;
    
    @Column(name = "cereja", nullable = false)
    private int cereja;
    
    @Column(name = "leiteCondensado", nullable = false)
    private int leiteCondensado;
    
    @Column(name = "coberturaMorango", nullable = false)
    private int coberturaMorango;
    
    @Column(name = "coberturaChocolate", nullable = false)
    private int coberturaChocolate;
    
    @Column(name = "leitePo", nullable = false)
    private int leitePo;
    
    @Column(name = "pacoca", nullable = false)
    private int pacoca;
    
    @Column(name = "chocoball", nullable = false)
    private int chocoball;

    public ItemPedido(int tamanho, int morango, int banana, int cereja, int leiteCondensado, int coberturaMorango, int coberturaChocolate, int leitePo, int pacoca, int chocoball, Pedido pedido, TamanhoAcai tamanhoAcai) {
        this.tamanho = tamanho;
        this.morango = morango;
        this.banana = banana;
        this.cereja = cereja;
        this.leiteCondensado = leiteCondensado;
        this.coberturaMorango = coberturaMorango;
        this.coberturaChocolate = coberturaChocolate;
        this.leitePo = leitePo;
        this.pacoca = pacoca;
        this.chocoball = chocoball;
        this.itemPedidoPK.setPedido(pedido);
        this.itemPedidoPK.setTamanhoAcai(tamanhoAcai);
    }

    public Pedido getPedido() {
        return itemPedidoPK.getPedido();
    }

    public void setPedido(Pedido pedido) {
        this.itemPedidoPK.setPedido(pedido);
    }

    public TamanhoAcai getTamanhoAcai() {
        return itemPedidoPK.getTamanhoAcai();
    }

    public void setAcai(TamanhoAcai tamanhoAcai) {
        this.itemPedidoPK.setTamanhoAcai(tamanhoAcai);
    }

    public int getTamanho() {
        return tamanho;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public int getMorango() {
        return morango;
    }

    public void setMorango(int morango) {
        this.morango = morango;
    }

    public int getBanana() {
        return banana;
    }

    public void setBanana(int banana) {
        this.banana = banana;
    }

    public int getCereja() {
        return cereja;
    }

    public void setCereja(int cereja) {
        this.cereja = cereja;
    }

    public int getLeiteCondensado() {
        return leiteCondensado;
    }

    public void setLeiteCondensado(int leiteCondensado) {
        this.leiteCondensado = leiteCondensado;
    }

    public int getCoberturaMorango() {
        return coberturaMorango;
    }

    public void setCoberturaMorango(int coberturaMorango) {
        this.coberturaMorango = coberturaMorango;
    }

    public int getCoberturaChocolate() {
        return coberturaChocolate;
    }

    public void setCoberturaChocolate(int coberturaChocolate) {
        this.coberturaChocolate = coberturaChocolate;
    }

    public int getLeitePo() {
        return leitePo;
    }

    public void setLeitePo(int leitePo) {
        this.leitePo = leitePo;
    }

    public int getPacoca() {
        return pacoca;
    }

    public void setPacoca(int pacoca) {
        this.pacoca = pacoca;
    }

    public int getChocoball() {
        return chocoball;
    }

    public void setChocoball(int chocoball) {
        this.chocoball = chocoball;
    }

//    @Override
//    public String toString() {
//        return nome;
//    }
    public Object[] toArray() throws ParseException {
        return new Object[]{this};
    }
}
