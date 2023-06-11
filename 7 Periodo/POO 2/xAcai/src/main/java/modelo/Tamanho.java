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
import javax.persistence.OneToMany;
import javax.persistence.PreRemove;
import javax.persistence.Table;

/**
 *
 * @author CONEXOS
 */
@Entity
@Table(name = "Tamanho", schema = "public")
public class Tamanho implements Serializable {

    @Id
    @Column(name = "id", nullable = false, updatable = false)
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    @Column(name = "tamanho", nullable = false, updatable = false)
    private String tamanho;

    @OneToMany(mappedBy = "tamanho", fetch = FetchType.EAGER)
    private List<TamanhoAcai> tamanhoAcai;

    public Tamanho() {
    }

    public Tamanho(String tamanho) {
        this.tamanho = tamanho;
        this.tamanhoAcai = new ArrayList<>(); // Inicializa a lista de pedidos vazia
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTamanho() {
        return tamanho;
    }

    public void setTamanho(String tamanho) {
        this.tamanho = tamanho;
    }

    public List<TamanhoAcai> getTamanhoAcai() {
        return tamanhoAcai;
    }

    public void setTamanhoAcai(List<TamanhoAcai> tamanhoAcai) {
        this.tamanhoAcai = tamanhoAcai;
    }

    @Override
    public String toString() {
        return tamanho;
    }

    public Object[] toArray() throws ParseException {
        return new Object[]{this};
    }

    @PreRemove
    public void preRemove() {
        for (TamanhoAcai tamanhoAcais : tamanhoAcai) {
            tamanhoAcais.setTamanho(null);
        }
    }

    public void addTamanhoAcai(TamanhoAcai tamanhoAcai) {
        if (tamanhoAcai != null) {
            tamanhoAcai.setTamanho(this); // Configura o cliente para o pedido
            this.tamanhoAcai.add(tamanhoAcai); // Adiciona o pedido à lista de pedidos do cliente
        }
    }
}
