/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

/**
 *
 * @author CONEXOS
 */
public class ItemPedido {
    private Pedido pedido;
    private Acai acai;
    private int tamanho;
    private int morango;
    private int banana;
    private int cereja;
    private int leiteCondensado;
    private int coberturaMorango;
    private int coberturaChocolate;
    private int leitePo;
    private int pacoca;
    private int chocoball;

    public ItemPedido(Pedido pedido, Acai acai, int tamanho, int morango, int banana, int cereja, int leiteCondensado, int coberturaMorango, int coberturaChocolate, int leitePo, int pacoca, int chocoball) {
        this.pedido = pedido;
        this.acai = acai;
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
    }

    public Pedido getPedido() {
        return pedido;
    }

    public void setPedido(Pedido pedido) {
        this.pedido = pedido;
    }

    public Acai getAcai() {
        return acai;
    }

    public void setAcai(Acai acai) {
        this.acai = acai;
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
    
    
}
