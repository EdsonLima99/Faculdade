/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import java.io.Serializable;
import java.text.ParseException;
import java.util.List;
import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
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
    
    @OneToMany (mappedBy = "tamanho", fetch = FetchType.LAZY, cascade = CascadeType.ALL)
    private List<TamanhoAcai> tamanhoAcai;
    
    public Acai() {
    }

    public Acai(String nome) {
        this.nome = nome;
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
}
