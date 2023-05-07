/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import java.io.Serializable;
import java.text.ParseException;
import javax.persistence.Embeddable;
import javax.persistence.FetchType;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;

/**
 *
 * @author CONEXOS
 */
@Embeddable
public class ItemPedidoPK implements Serializable {

    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "idTamanhoAcai")
    private TamanhoAcai tamanhoAcai;

    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "idPedido")
    private Pedido pedido;

    public ItemPedidoPK() {
    }

    public ItemPedidoPK(TamanhoAcai tamanhoAcai, Pedido pedido) {
        this.tamanhoAcai = tamanhoAcai;
        this.pedido = pedido;
    }

    public TamanhoAcai getTamanhoAcai() {
        return tamanhoAcai;
    }

    public void setTamanhoAcai(TamanhoAcai tamanhoAcai) {
        this.tamanhoAcai = tamanhoAcai;
    }

    public Pedido getPedido() {
        return pedido;
    }

    public void setPedido(Pedido pedido) {
        this.pedido = pedido;
    }

//    @Override
//    public String toString() {
//        return "ItemPedidoPK{" + "tamanhoAcai=" + tamanhoAcai + ", pedido=" + pedido + '}';
//    }
    public Object[] toArray() throws ParseException {
        return new Object[]{this};
    }
}
