CREATE TABLE especialidade (
    idespecialidade SERIAL PRIMARY KEY,
    descricao VARCHAR(30)
);

CREATE TABLE medico (
    crm SERIAL PRIMARY KEY,
    nomeMedico VARCHAR(30),
    cpf VARCHAR(15)
);

CREATE TABLE especialidade_medico (
    fk_especialidade_idespecialidade INTEGER REFERENCES especialidade(idespecialidade),
    fk_medico_crm INTEGER REFERENCES medico(crm),
	PRIMARY KEY (fk_especialidade_idespecialidade, fk_medico_crm)
);

CREATE TABLE paciente (
    idpaciente SERIAL PRIMARY KEY,
    nomePaciente VARCHAR(30),
    cpf VARCHAR(15)
);

CREATE TABLE consulta (
    idconsulta SERIAL PRIMARY KEY,
    data DATE,
    descricao VARCHAR(30),
    fk_medico_crm INTEGER REFERENCES medico(crm),
    fk_paciente_idpaciente INTEGER REFERENCES paciente(idpaciente)
);

ALTER TABLE paciente ADD rg VARCHAR(9);

ALTER TABLE especialidade ADD CONSTRAINT especialidade_unica UNIQUE(descricao);

ALTER TABLE consulta DROP COLUMN descricao;
ALTER TABLE consultar ADD descricaoconsulta VARCHAR(30);


