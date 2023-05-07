/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import java.io.Serializable;
import java.text.ParseException;
import java.util.List;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;

/**
 *
 * @author CONEXOS
 */
@Entity
@Table(name = "TamanhoAcai", schema = "public")
public class TamanhoAcai implements Serializable {

    @Id
    @Column(name = "id", nullable = false)
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    @Column(name = "valor", nullable = false)
    private float valor;

    @ManyToOne
    @JoinColumn(name = "idAcai", nullable = false)
    private Acai acai;

    @ManyToOne
    @JoinColumn(name = "idTamanho", nullable = false)
    private Tamanho tamanho;

//    @OneToMany(mappedBy = "itemPedidoPK.tamanhoAcai")
//    private List<ItemPedido> itemPedido;

    public TamanhoAcai() {
    }

    public TamanhoAcai(float valor, Acai acai, Tamanho tamanho) {
        this.valor = valor;
        this.acai = acai;
        this.tamanho = tamanho;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public float getValor() {
        return valor;
    }

    public void setValor(float valor) {
        this.valor = valor;
    }

    public Acai getAcai() {
        return acai;
    }

    public void setAcai(Acai acai) {
        this.acai = acai;
    }

    public Tamanho getTamanho() {
        return tamanho;
    }

    public void setTamanho(Tamanho tamanho) {
        this.tamanho = tamanho;
    }

//    public List<ItemPedido> getItemPedido() {
//        return itemPedido;
//    }
//
//    public void setItemPedido(List<ItemPedido> itemPedido) {
//        this.itemPedido = itemPedido;
//    }

//    @Override;
//    public String toString() {
//        return "TamanhoAcai{" + "valor=" + valor + ", acai=" + acai + ", tamanho=" + tamanho + '}';
//    }
    public Object[] toArray() throws ParseException {
        return new Object[]{this};
    }
}
