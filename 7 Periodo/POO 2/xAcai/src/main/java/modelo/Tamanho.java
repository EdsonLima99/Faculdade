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
@Table(name = "Tamanho", schema = "public")
public class Tamanho implements Serializable {

    @Id
    @Column(name = "id", nullable = false, updatable = false)
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    @Column(name = "tamanho", nullable = false, updatable = false)
    private String tamanho;
    
    @OneToMany (mappedBy = "tamanho", fetch = FetchType.LAZY, cascade = CascadeType.ALL)
    private List<TamanhoAcai> tamanhoAcai;
    
    public Tamanho() {
    }

    public Tamanho(String tamanho) {
        this.tamanho = tamanho;
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
}
