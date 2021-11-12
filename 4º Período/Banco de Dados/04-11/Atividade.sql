CREATE TABLE Cliente(
    idCliente SERIAL PRIMARY KEY,
    nomeCliente VARCHAR(30)
);

CREATE TABLE Venda(
    idVenda SERIAL PRIMARY KEY,
    dtCompra TIMESTAMP,
	idCliente INTEGER REFERENCES Cliente(idCliente)
);

CREATE TABLE Produto(
    idProduto SERIAL PRIMARY KEY,
    nomeProduto VARCHAR(30),
    valor FLOAT
);

CREATE TABLE ItensVenda(
    idVenda INTEGER REFERENCES Venda(idVenda),
    idProduto INTEGER REFERENCES Produto(idProduto),
    quantidade INTEGER,
	PRIMARY KEY (idVenda, idProduto)
);

INSERT INTO CLiente (nomeCliente) VALUES ('Cliente 1'), ('Cliente 2'), ('Cliente 3'), ('Cliente 4'), ('Cliente 5');
INSERT INTO Venda (idCliente, dtCompra) VALUES (1, '2021-11-10'), (2, '2021-11-09'), (3, '2021-11-08'), (4, '2021-11-07'), (5, '2021-11-06');
INSERT INTO Produto (nomeProduto, valor) VALUES ('Produto 1', 10), ('Produto 2', 15), ('Produto 3', 20), ('Produto 4', 2), ('Produto 5', 5);
INSERT INTO ItensVenda (idVenda, idProduto, quantidade) VALUES (1, 1, 10), (2, 2, 5), (3, 3, 30), (4, 4, 20), (5, 5, 15);

DELETE FROM ItensVenda WHERE idVenda IN (SELECT idVenda FROM Venda WHERE idCliente = 1);
DELETE FROM Venda WHERE idCliente = 1;
DELETE FROM Cliente WHERE idCliente = 1;

SELECT v.dtCompra as Data, (iv.quantidade * p.valor) as Total FROM Venda v, ItensVenda iv, Produto p WHERE p.idProduto = iv.idProduto and v.idVenda = iv.idVenda;

SELECT c.nomeCliente FROM Cliente c, Venda v WHERE c.idCliente = v.idCliente and EXTRACT(MONTH FROM v.dtCompra) = '11';

SELECT c.idCliente, c.nomeCliente, SUM(iv.quantidade * p.valor) as Total 
FROM Cliente c
LEFT JOIN Venda v
LEFT JOIN ItensVenda iv
LEFT JOIN Produto p
ON p.idProduto = iv.idProduto and v.idVenda = iv.idVenda and c.idCliente = v.idCliente 
GROUP BY c.idCliente
ORDER BY Total;