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
@Table(name = "Acai", schema = "public")
public class Acai implements Serializable {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    @Column(name = "nome", nullable = false)
    private String nome;

    @OneToMany(mappedBy = "tamanho", fetch = FetchType.EAGER)
    private List<TamanhoAcai> tamanhoAcai;

    public Acai() {
    }

    public Acai(String nome) {
        this.nome = nome;
        this.tamanhoAcai = new ArrayList<>(); // Inicializa a lista de pedidos vazia
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public List<TamanhoAcai> getTamanhoAcai() {
        return tamanhoAcai;
    }

    public void setTamanhoAcai(List<TamanhoAcai> tamanhoAcai) {
        this.tamanhoAcai = tamanhoAcai;
    }

    @Override
    public String toString() {
        return nome;
    }

    public Object[] toArray() throws ParseException {
        return new Object[]{this};
    }

    @PreRemove
    public void preRemove() {
        for (TamanhoAcai tamanhoAcais : tamanhoAcai) {
            tamanhoAcais.setAcai(null);
        }
    }

    public void addTamanhoAcai(TamanhoAcai tamanhoAcai) {
        if (tamanhoAcai != null) {
            tamanhoAcai.setAcai(this); // Configura o cliente para o pedido
            this.tamanhoAcai.add(tamanhoAcai); // Adiciona o pedido à lista de pedidos do cliente
        }
    }
}
