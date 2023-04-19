/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

import gerenciador.FuncoesUteis;
import java.text.ParseException;
import java.util.Date;
import javax.swing.ImageIcon;

/**
 *
 * @author CONEXOS
 */
public class Cliente {

    private int id;
    private String nome;
    private String cpf;
    private Date dataNascimento;
    private String cep;
    private String endereco;
    private int numero;
    private String bairro;
    private String referencia;
    private String cidade;
    private String telefone;
    private String celular;
    private String email;
    private char sexo;
    private byte[] foto;

    public Cliente(String nome, String cpf, Date dataNascimento, String cep, String endereco, int numero, String bairro, String referencia, String cidade, String telefone, String celular, String email, char sexo, byte[] foto) {
        this.nome = nome;
        this.cpf = cpf;
        this.dataNascimento = dataNascimento;
        this.cep = cep;
        this.endereco = endereco;
        this.numero = numero;
        this.bairro = bairro;
        this.referencia = referencia;
        this.cidade = cidade;
        this.telefone = telefone;
        this.celular = celular;
        this.email = email;
        this.sexo = sexo;
        this.foto = foto;
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

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public Date getDataNascimento() {
        return dataNascimento;
    }
    
    public String getDataNascimentoFormatada() throws ParseException {
        return FuncoesUteis.dateToStr(dataNascimento);
    }

    public void setDataNascimento(Date dataNascimento) {
        this.dataNascimento = dataNascimento;
    }

    public String getCep() {
        return cep;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public String getReferencia() {
        return referencia;
    }

    public void setReferencia(String referencia) {
        this.referencia = referencia;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public String getCelular() {
        return celular;
    }

    public void setCelular(String celular) {
        this.celular = celular;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public char getSexo() {
        return sexo;
    }

    public void setSexo(char sexo) {
        this.sexo = sexo;
    }

    public byte[] getFoto() {
        return foto;
    }

    public ImageIcon getFotoImage() {
        if (foto != null) {
            return new ImageIcon(foto);
        } else {
            return null;
        }
    }

    public void setFoto(byte[] foto) {
        this.foto = foto;
    }
    
    @Override
    public String toString() {
        return nome;
    }
    
    public Object[] toArray() throws ParseException{
        return new Object[] {this, bairro, cidade, getDataNascimentoFormatada(), getFotoImage()};
    }
}
