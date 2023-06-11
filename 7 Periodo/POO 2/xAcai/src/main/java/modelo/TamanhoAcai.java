/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import java.io.Serializable;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.PreRemove;
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
    private Double valor;

    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "idAcai", nullable = false)
    private Acai acai;

    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "idTamanho", nullable = false)
    private Tamanho tamanho;

    @OneToMany(mappedBy = "tamanhoAcai", fetch = FetchType.EAGER)
    private List<ItemPedido> itemPedido;

    public TamanhoAcai() {
    }

    public TamanhoAcai(Acai acai, Tamanho tamanho, Double valor) {
        this.acai = acai;
        this.tamanho = tamanho;
        this.valor = valor;

        if (acai != null) {
            acai.addTamanhoAcai(this); // Configura o pedido para o cliente
        }

        if (tamanho != null) {
            tamanho.addTamanhoAcai(this); // Configura o pedido para o cliente
        }

        this.itemPedido = new ArrayList<>(); // Inicializa a lista de pedidos vazia
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Double getValor() {
        return valor;
    }

    public void setValor(Double valor) {
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

    public List<ItemPedido> getItemPedido() {
        return itemPedido;
    }

    public void setItemPedido(List<ItemPedido> itemPedido) {
        this.itemPedido = itemPedido;
    }

    @Override
    public String toString() {
        return String.valueOf(valor);
    }

    public Object[] toArray() throws ParseException {
        return new Object[]{acai, tamanho, this};
    }

    @PreRemove
    public void preRemove() {
        for (ItemPedido itemPedidos : itemPedido) {
            itemPedidos.setTamanhoAcai(null);
        }
    }

    public void addItemPedido(ItemPedido itemPedido) {
        if (itemPedido != null) {
            itemPedido.setTamanhoAcai(this); // Configura o cliente para o pedido
            this.itemPedido.add(itemPedido); // Adiciona o pedido à lista de pedidos do cliente
        }
    }
}
