/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import modelo.Cliente;

/**
 *
 * @author CONEXOS
 */
public class ClienteDAO {

    public void inserir(Cliente cliente) throws ClassNotFoundException, SQLException {
        String sql = "INSERT INTO cliente("
                + "nome, cpf, datanascimento, cep, endereco, numero, bairro, referencia, cidade, telefone, celular, "
                + "email, sexo, foto) "
                + "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

        PreparedStatement preparedStatement = ConexaoPostgres.obterConexao().prepareStatement(sql, PreparedStatement.RETURN_GENERATED_KEYS);

        int indice = 1;
        preparedStatement.setString(indice++, cliente.getNome());
        preparedStatement.setString(indice++, cliente.getCpf());
        preparedStatement.setDate(indice++, new java.sql.Date(cliente.getDataNascimento().getTime()));
        preparedStatement.setString(indice++, cliente.getCep());
        preparedStatement.setString(indice++, cliente.getEndereco());
        preparedStatement.setInt(indice++, cliente.getNumero());
        preparedStatement.setString(indice++, cliente.getBairro());
        preparedStatement.setString(indice++, cliente.getReferencia());
        preparedStatement.setString(indice++, cliente.getCidade());
        preparedStatement.setString(indice++, cliente.getTelefone());
        preparedStatement.setString(indice++, cliente.getCelular());
        preparedStatement.setString(indice++, cliente.getEmail());
        preparedStatement.setString(indice++, String.valueOf(cliente.getSexo()));
        preparedStatement.setBytes(indice++, cliente.getFoto());

        preparedStatement.execute();

        ResultSet resultSet = preparedStatement.getGeneratedKeys();
        if (resultSet.next()) {
            int id = resultSet.getInt(1);
            cliente.setId(id);
        }
    }

//    public List<Cliente> listar() throws ClassNotFoundException, SQLException{
//        Statement statement;
//        statement = ConexaoPostgres.obterConexao().createStatement();
//        List<Cliente> lista = new ArrayList();
//        Cliente cliente;
//        
//        String sql = "SELECT * FROM CLIENTE";
//        ResultSet resultSet = statement.executeQuery(sql);
//        
//        while(resultSet.next()){
//            cliente = new Cliente(resultSet.getInt("id"), resultSet.getString("nome"));
//        }
//    }
}
