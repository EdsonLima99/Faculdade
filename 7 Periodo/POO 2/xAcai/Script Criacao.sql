CREATE TABLE IF NOT EXISTS Acai
(
    id SERIAL NOT NULL PRIMARY KEY,
    nome varchar(255) not null,
	valor float not null
);

CREATE TABLE IF NOT EXISTS Cliente
(
    id SERIAL NOT NULL PRIMARY KEY,
    nome varchar(255) not null,
	cpf char(11) not null,
	dataNascimento date not null,
	cep char(8) not null,
	endereco varchar(255) not null,
	numero integer not null,
	bairro varchar(255) not null,
	referencia varchar(255),
	cidade varchar(255) not null,
	telefone varchar(255),
	celular varchar(255) not null,
	email varchar(255),
	sexo char(1) not null,
	foto bytea not null
);

CREATE TABLE IF NOT EXISTS Pedido
(
    id SERIAL NOT NULL PRIMARY KEY,
    data Date not null,
	entrega char(1) not null,
	valorTotal float not null,
	idCliente integer not null references Cliente(id)
);

CREATE TABLE IF NOT EXISTS ItemPedido
(
    idPedido integer NOT NULL references Pedido(id),
	idAcai integer not null references Acai(id),
	tamanho integer not null,
    morango integer not null,
    banana integer not null,
    cereja integer not null,
    leiteCondensado integer not null,
    coberturaMorango integer not null,
    coberturaChocolate integer not null,
    leitePo integer not null,
    pacoca integer not null,
    chocoball integer not null,
	primary key(idPedido, idACai)
);