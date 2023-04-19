/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import modelo.Acai;

/**
 *
 * @author CONEXOS
 */
public class AcaiDAO {

    public void inserir(Acai acai) throws ClassNotFoundException, SQLException {
        String sql = "INSERT INTO acai("
                + "nome, valor)"
                + "VALUES (?, ?)";

        PreparedStatement preparedStatement = ConexaoPostgres.obterConexao().prepareStatement(sql, PreparedStatement.RETURN_GENERATED_KEYS);

        int indice = 1;
        preparedStatement.setString(indice++, acai.getNome());
        preparedStatement.setFloat(indice++, acai.getValor());

        preparedStatement.execute();

        ResultSet resultSet = preparedStatement.getGeneratedKeys();
        if (resultSet.next()) {
            int id = resultSet.getInt(1);
            acai.setId(id);
        }
    }

    public void alterar(Acai acai) throws ClassNotFoundException, SQLException {
        String sql = "UPDATE acai SET nome = ?, valor = ? WHERE ID = " + acai.getId();

        PreparedStatement preparedStatement = ConexaoPostgres.obterConexao().prepareStatement(sql, PreparedStatement.RETURN_GENERATED_KEYS);

        int indice = 1;
        preparedStatement.setString(indice++, acai.getNome());
        preparedStatement.setFloat(indice++, acai.getValor());

        preparedStatement.execute();
    }

    public List<Acai> listar() throws ClassNotFoundException, SQLException {
        Statement statement;
        statement = ConexaoPostgres.obterConexao().createStatement();
        List<Acai> lista = new ArrayList();
        Acai acai;

        String sql = "SELECT * FROM ACAI";
        ResultSet resultSet = statement.executeQuery(sql);

        while (resultSet.next()) {
            acai = new Acai(resultSet.getString("nome"), resultSet.getFloat("valor"));
        }
        return lista;
    }

    private List<Acai> pesquisar(String string, int tipo) throws ClassNotFoundException, SQLException {
        Statement statement;
        statement = ConexaoPostgres.obterConexao().createStatement();
        List<Acai> lista = new ArrayList();
        Acai acai;

        String sql = "SELECT * FROM ACAI WHERE";
        switch (tipo) {
            case 1:
                sql = sql + " NOME LIKE '%" + string + "%'";
                break;
            case 2:
                sql = sql + " VALOR = " + Float.parseFloat(string);
                break;
        }
        ResultSet resultSet = statement.executeQuery(sql);

        while (resultSet.next()) {
            acai = new Acai(resultSet.getString("nome"), resultSet.getFloat("valor"));
            acai.setId(resultSet.getInt("id"));
            lista.add(acai);
        }
        return lista;
    }
    
    public List<Acai> pesquisarPorNome(String string) throws ClassNotFoundException, SQLException{
        return pesquisar(string, 1);
    }
    
    public List<Acai> pesquisarPorValor(String string) throws ClassNotFoundException, SQLException{
        return pesquisar(string, 2);
    }
    
    public void excluir(Acai acai) throws ClassNotFoundException, SQLException {
        Statement statement;
        statement = ConexaoPostgres.obterConexao().createStatement();

        String sql = "DELETE FROM ACAI WHERE ID = " + acai.getId();
        statement.execute(sql);
    }
}
