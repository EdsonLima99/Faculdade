create table Mecanicos
(
	codigo_Mecanico serial not null primary key,
	mecanico varchar(20) not null,
	comissao decimal(5,2)
);

create table Clientes
(
	codigo_Cliente serial not null primary key,
	nome varchar(20) not null
);

create table Telefone
(
	id_Telefone serial not null primary key,
	telefone varchar(11) not null,
	codigo_Cliente integer not null references Clientes (codigo_Cliente)
);

create table Ordens_Servico
(
	codigo_OS serial not null primary key,
	data date not null,
	status boolean not null,
	codigo_Cliente integer not null references Clientes (codigo_Cliente),
	codigo_Mecanico integer not null references Mecanicos (codigo_Mecanico)
); 

create table Tipos_Servico
(
	codigo_Tipo serial not null primary key,
	tipo_Servico varchar(20) not null
);

create table Servicos
(
	codigo_Servicos serial not null primary key,
	servico varchar(40) not null,
	valor float not null,
	codigo_Tipo integer not null references Tipos_Servico (codigo_Tipo)
);

create table Itens_OS
(
	codigo_Servicos integer not null references Servicos (codigo_Servicos),
	codigo_OS integer not null references Ordens_Servico (codigo_OS),
	quantidade integer not null,
	primary key (codigo_Servicos, codigo_OS)
);