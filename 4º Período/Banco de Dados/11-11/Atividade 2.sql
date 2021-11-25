/*CREATE TABLE Endereco(
	idEndereco SERIAL NOT NULL PRIMARY KEY,
	rua VARCHAR(30) NOT NULL,
	numero INTEGER NOT NULL,
	bairro VARCHAR(30) NOT NULL,
	cidade VARCHAR(30) NOT NULL
);*/

CREATE TABLE Pessoa(
	matricula SERIAL NOT NULL PRIMARY KEY,
	nome VARCHAR(30) NOT NULL,
	dataNascimento DATE NOT NULL,
	endereco VARCHAR(30) NOT NULL
	breve INTEGER,
	idAluno INTEGER,
	idInstrutor INTEGER REFERENCES Instrutor(idInstrutor)
	/*idEndereco INTEGER NOT NULL REFERENCES Endereco(idEndereco)*/
);

CREATE TABLE Instrutor(
	idInstutor SERIAL NOT NULL PRIMARY KEY,
	instituicao VARCHAR(30) NOT NULL,
	nomeCurso VARCHAR(30) NOT NULL,
	dataCurso DATE NOT NULL
);

CREATE TABLE Saida(
	idSaida SERIAL NOT NULL PRIMARY KEY,
	data DATE NOT NULL,
	horaSaida TIME NOT NULL,
	horaChegada TIME NOT NULL,
	parece VARCHAR(30) NOT NULL
	idAluno INTEGER NOT NULL REFERENCES Pessoa(idAluno),
	matricula INTEGER NOT NULL REFERENCES Pessoa(matricula),
	idInstrutor INTEGER NOT NULL REFERENCES Instrutor(idInstrutor)
);