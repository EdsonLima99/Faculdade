/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import java.io.Serializable;
import java.text.ParseException;
import java.util.Date;
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
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

/**
 *
 * @author CONEXOS
 */
@Entity
@Table(name = "Pedido", schema = "public")
public class Pedido implements Serializable {

    @Id
    @Column(name = "id", nullable = false)
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    @Column(name = "data", nullable = false)
    @Temporal(TemporalType.DATE)
    private Date data;

    @Column(name = "entrega", nullable = false)
    private char entrega;

    @Column(name = "valorTotal", nullable = false)
    private float valorTotal;

    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "idCliente", nullable = false)
    private Cliente cliente;

    @OneToMany(mappedBy = "itemPedidoPK.pedido")
    private List<ItemPedido> itemPedido;

    public Pedido() {
    }

    public Pedido(Date data, char entrega, float valorTotal, Cliente cliente) {
        this.data = data;
        this.entrega = entrega;
        this.valorTotal = valorTotal;
        this.cliente = cliente;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public Date getData() {
        return data;
    }

    public void setData(Date data) {
        this.data = data;
    }

    public char getEntrega() {
        return entrega;
    }

    public void setEntrega(char entrega) {
        this.entrega = entrega;
    }

    public float getValorTotal() {
        return valorTotal;
    }

    public void setValorTotal(float valorTotal) {
        this.valorTotal = valorTotal;
    }

    public List<ItemPedido> getItemPedido() {
        return itemPedido;
    }

    public void setItemPedido(List<ItemPedido> itemPedido) {
        this.itemPedido = itemPedido;
    }

    public Object[] toArray() throws ParseException {
        return new Object[]{this};
    }
}
