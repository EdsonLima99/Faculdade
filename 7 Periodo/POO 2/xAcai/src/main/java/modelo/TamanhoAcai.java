/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import java.io.Serializable;
import java.text.ParseException;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
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

    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "idAcai", nullable = false)
    private Acai acai;

    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "idTamanho", nullable = false)
    private Tamanho tamanho;

    public TamanhoAcai() {
    }

    public TamanhoAcai(Acai acai, Tamanho tamanho, float valor) {
        this.acai = acai;
        this.tamanho = tamanho;
        this.valor = valor;
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

    public Object[] toArray() throws ParseException {
        return new Object[]{acai.getNome(), tamanho.getTamanho(), valor};
    }
}
