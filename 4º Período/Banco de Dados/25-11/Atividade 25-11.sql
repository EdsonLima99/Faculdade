drop table Cursa;
drop table Alunos;
drop table CargaHoraria;
drop table Disciplinas;
drop table TipoDisciplinas;
drop table Cursos;
drop table Professores;

CREATE TABLE Cursos (
    idCurso serial PRIMARY KEY,
    nomeCurso varchar(30)
);

CREATE TABLE Professores (
    idProfessor serial PRIMARY KEY,
    nomeProfessor varchar(30) not null unique,
    departamento varchar(20)
);
CREATE TABLE Alunos (
    idAluno serial PRIMARY KEY,
    nomeAluno varchar(30) not null unique,
    cidade varchar(30),
    estado varchar(2),
	idcurso int references Cursos(idCurso),
	idOrientador int references Professores(idProfessor)
);


CREATE TABLE TipoDisciplinas (
    idTipoDisciplina serial PRIMARY KEY,
    Tipo varchar(20)
);

CREATE TABLE Disciplinas (
    idDisciplina serial PRIMARY KEY,
    nomeDisciplina varchar(30),
    cargaHoraria int,
    idTipoDisciplina int references TipoDisciplinas(idTipoDisciplina),
    idProfessor int references Professores(idProfessor),
	idCurso int references Cursos(idCurso)
);

CREATE TABLE Cursa (
    semestre varchar(10),
    idAluno int references Alunos(idAluno),
    idDisciplina int references Disciplinas(idDisciplina),
    nota numeric(5,2) not null,
	dtInicio timestamp,
    PRIMARY KEY (semestre, idAluno, idDisciplina)
);


CREATE TABLE CargaHoraria (
    idCurso int references Cursos(idCurso),
    idTipoDisciplina int references TipoDisciplinas(idTipoDisciplina),
    cargaHoraria int,
    PRIMARY KEY (idCurso, idTipoDisciplina)
);

insert into Cursos (nomeCurso) values ('SISTEMAS DE INFORMACAO');
insert into Cursos (nomeCurso) values ('ADMINISTRACAO');
insert into Cursos (nomeCurso) values ('SANEAMENTO AMBIENTAL');

insert into professores (nomeProfessor, departamento) values ('VANDERSON SAM', 'INFORMATICA');
insert into professores (nomeProfessor, departamento) values ('TEDESCO FROSSARD', 'INFORMATICA');
insert into professores (nomeProfessor, departamento) values ('THIAGO SAQUE', 'ADMINISTRACAO');
insert into professores (nomeProfessor, departamento) values ('JULIO NARDOVISK', 'BASICO');
insert into professores (nomeProfessor, departamento) values ('LUANITA', 'ADMINISTRACAO');

insert into alunos (nomeAluno, cidade, estado, idCurso, idOrientador) values ('IGOR CARLOS PULINI','COLATINA','ES',1, 1);
insert into alunos (nomeAluno, cidade, estado, idCurso, idOrientador) values ('RENAN OSORIO RIOS','COLATINA','ES',2,2);
insert into alunos (nomeAluno, cidade, estado, idCurso, idOrientador) values ('ALAN FROSSARD','SAO ROQUE','ES',1,3);
insert into alunos (nomeAluno, cidade, estado, idCurso, idOrientador) values ('GIOVANY FORZZA','VITORIA','ES',2,4);
insert into alunos (nomeAluno, cidade, estado, idCurso, idOrientador) values ('HERON BATISTA','IPATINGA','MG',1,1);
insert into alunos (nomeAluno, cidade, estado, idCurso, idOrientador) values ('DIONE MAFIOLAT','RIO DE JANEIRO','RJ',1,null);
insert into alunos (nomeAluno, cidade, estado, idCurso, idOrientador) values ('LUIZ REINOSO','NITEROI','RJ',1,null);

insert into TipoDisciplinas (tipo) values ('BASICAS');
insert into TipoDisciplinas (tipo) values ('COMPLEMENTARES'); 

insert into CargaHoraria (idCurso, idTipoDisciplina, cargaHoraria) values (1,1,450);
insert into CargaHoraria (idCurso, idTipoDisciplina, cargaHoraria) values (1,2,200);
insert into CargaHoraria (idCurso, idTipoDisciplina, cargaHoraria) values (2,1,400);
insert into CargaHoraria (idCurso, idTipoDisciplina, cargaHoraria) values (2,2,100);
insert into CargaHoraria (idCurso, idTipoDisciplina, cargaHoraria) values (3,1,200);
insert into CargaHoraria (idCurso, idTipoDisciplina, cargaHoraria) values (3,2,100);

insert into Disciplinas (nomeDisciplina, cargaHoraria, idTipoDisciplina, idProfessor,idCurso) values ('Banco de Dados',150,1,1,1);
insert into Disciplinas (nomeDisciplina, cargaHoraria, idTipoDisciplina, idProfessor,idCurso) values ('Estrutura de Dados',200,1,2,1);
insert into Disciplinas (nomeDisciplina, cargaHoraria, idTipoDisciplina, idProfessor,idCurso) values ('Redes',150,1,3,1);
insert into Disciplinas (nomeDisciplina, cargaHoraria, idTipoDisciplina, idProfessor,idCurso) values ('Inteligencia Computacional',200,2,5,1);
insert into Disciplinas (nomeDisciplina, cargaHoraria, idTipoDisciplina, idProfessor,idCurso) values ('Etica e Sociedade',250,2,5,1);
insert into Disciplinas (nomeDisciplina, cargaHoraria, idTipoDisciplina, idProfessor,idCurso) values ('Administracao Producao',150,1,1,2);
insert into Disciplinas (nomeDisciplina, cargaHoraria, idTipoDisciplina, idProfessor,idCurso) values ('Calculo',250,1,1,2);
insert into Disciplinas (nomeDisciplina, cargaHoraria, idTipoDisciplina, idProfessor,idCurso) values ('Pesquisa Operacional',150,2,3,2);

insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 1, 1, '98.5','01/03/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 1, 2, '90','10/02/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 1, 3, '95','12/03/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-2', 1, 4, '92.5','25/07/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-2', 1, 5, '80','20/07/2021' );

insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 2, 1, '60','01/03/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 2, 2, '40','10/02/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 2, 3, '45','12/03/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-2', 2, 4, '25.5','25/07/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-2', 2, 5, '70','20/07/2021' );

insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 3, 1, '28.5','12/04/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 3, 2, '75','10/02/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 3, 5, '85','12/03/2021' );

insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 4, 6, '90','15/01/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-2', 4, 7, '80','10/07/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-2', 4, 8, '65','12/06/2021' );

insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-2', 5, 6, '50','01/07/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 5, 7, '60','10/02/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-1', 5, 8, '65','20/04/2021' );

insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-2', 7, 6, '80','25/07/2021' );
insert into Cursa (semestre, idAluno, idDisciplina, nota, dtInicio) values ('2021-2', 7, 7, '70','30/07/2021' );

01) Crie a estrutura necessária para armazenar as cidades e os estados dos Alunos, 
respeitando as regras formais, e em seguida, insira e relacione os dados na nova estrutura e exclua a estrutura antiga.

create table Estados(
	idEstado serial primary key,
	Estado varchar(30)
);

create table Cidades(
	idCidade serial primary key,
	Cidade varchar(30),
	idEstado integer references Estados(idEstado)
);

insert into Estados (Estado) values ('ES');
insert into Estados (Estado) values ('MG');
insert into Estados (Estado) values ('RJ');

insert into Cidades (Cidade, idEstado) values('COLATINA',1);
insert into Cidades (Cidade, idEstado) values('SAO ROQUE',1);
insert into Cidades (Cidade, idEstado) values('VITORIA',1);
insert into Cidades (Cidade, idEstado) values('IPATINGA',2);
insert into Cidades (Cidade, idEstado) values('RIO DE JANEIRO',3);
insert into Cidades (Cidade, idEstado) values('NITEROI',3);

alter table Alunos add idCidade integer references Cidades(idCidade);

update Alunos set idCidade = 1 where cidade = 'COLATINA';
update Alunos set idCidade = 2 where cidade = 'SAO ROQUE';
update Alunos set idCidade = 3 where cidade = 'VITORIA';
update Alunos set idCidade = 4 where cidade = 'IPATINGA';
update Alunos set idCidade = 5 where cidade = 'RIO DE JANEIRO';
update Alunos set idCidade = 6 where cidade = 'NITEROI';

alter table Alunos drop column Cidade;
alter table Alunos drop column Estado;

02) Crie a estrutura necessária para armazenar os Departamentos dos Professores, 
respeitando as regras formais, e em seguida, insira e relacione os dados na nova estrutura e exclua a estrutura antiga.
insert into professores (nomeProfessor, departamento) values ('VANDERSON SAM', 'INFORMATICA');
insert into professores (nomeProfessor, departamento) values ('TEDESCO FROSSARD', 'INFORMATICA');
insert into professores (nomeProfessor, departamento) values ('THIAGO SAQUE', 'ADMINISTRACAO');
insert into professores (nomeProfessor, departamento) values ('JULIO NARDOVISK', 'BASICO');
insert into professores (nomeProfessor, departamento) values ('LUANITA', 'ADMINISTRACAO');

create table Departamentos(
	idDepartamento serial primary key,
	Departamento varchar(30)
);

insert into Departamentos (Departamento) values ('INFORMATICA');
insert into Departamentos (Departamento) values ('ADMINISTRACAO');
insert into Departamentos (Departamento) values ('BASICO');

alter table Professores add idDepartamento integer references Departamentos(idDepartamento);

update Professores set idDepartamento = 1 where Departamento = 'INFORMATICA';
update Professores set idDepartamento = 2 where Departamento = 'ADMINISTRACAO';
update Professores set idDepartamento = 3 where Departamento = 'BASICO';

alter table Professores drop column Departamento;

03) Quais alunos são do curso de administração da cidade de Vitória?

select a.* 
from Alunos a, Cidades c 
where a.idCidade = c.idCidade and c.Cidade = 'VITORIA';

04) Crie um comando que retorne o número de alunos por curso, exiba também os cursos sem alunos.

select c.nomeCurso, count(a.*) as total
from Alunos a
right join Cursos c on a.idCurso = c.idCurso
group by c.nomeCurso;

05) Crie um comando que retorne o número de alunos por cidade.

select c.Cidade, count(a.*) as total
from Alunos a
right join Cidades c on a.idCidade = c.idCidade
group by c.Cidade;

06) Crie um comando que retorne o número de alunos por cidade e estado.

select e.Estado, c.Cidade, count(a.*) as total
from Alunos a
right join Cidades c on a.idCidade = c.idCidade
right join Estados e on c.idEstado = e.idEstado
group by e.Estado, c.Cidade;

07) Crie um comando que retorne o número de alunos por curso, cidade.

select cu.nomecurso, c.cidade, count(a.*) as total
from cursos cu
left join alunos a on cu.idcurso = a.idcurso
left join cidades c on a.idcidade = c.idcidade
group by cu.nomecurso, c.cidade;

08) Crie um comando que retorne o número de alunos por departamento.

select d.departamento, count(a.*) as total
from Alunos a
left join professores p on a.idorientador = p.idprofessor
left join departamentos d on p.iddepartamento = d.iddepartamento
group by d.departamento;

09) Crie um comando que retorne a lista de professores, sem repetição, que ministram aulas no curso de Sistemas de Informação.

select distinct p.nomeprofessor
from professores p
left join disciplinas d on p.idprofessor = d.idprofessor
left join cursos c on d.idcurso = c.idcurso and c.idcurso = 1;

10) Crie um comando que retorne os professores que não tem nenhuma disciplina.

select p.nomeprofessor
from professores p
where p.idprofessor not in(
	select p.idprofessor
	from professores p, disciplinas d
	where p.idprofessor = d.idprofessor
);

11) Crie um comando que retorne o número de disciplinas por professor.

select p.nomeprofessor, count(d.*) as totaldisciplinas
from professores p
left join disciplinas d on p.idprofessor = d.idprofessor
group by p.nomeprofessor;

12) Crie um comando que retorne os alunos que não tem nenhuma disciplina.

select a.nomealuno
from alunos a
where a.idaluno not in(
	select a.idaluno
	from alunos a, cursa c
	where a.idaluno = c.idaluno
);

13) Crie um comando que retorne em uma única lista o nome do aluno e o nome do professor, 
adicione uma coluna com nome de tipo, informando se é aluno ou professor.



14) Quais disciplinas foram iniciadas no mês de julho de 2021?
15) Quais disciplinas não tem nenhum aluno cursando?
16) Qual a carga horária de disciplinas ofertada por mês, curso.
17) Emita um histórico completo do aluno, com todas as disciplinas cursadas, o nome do aluno, a nota, o curso, o professor, o tipo de disciplina, para cada disciplina cursada, insira uma coluna que exiba a mensagem de aprovado (nota >= 6) ou reprovado.
18) Emita um relatório informando quais alunos já cursaram toda a carga horária de todos os tipos de disciplina.
19) Emita um relatório de todas as disciplinas por curso, com carga horária, nome da disciplina e tipo.
20) Emita um relatório das disciplinas que cada professor ministra, com nome da disciplina, tipo, carga horária e nome do curso.
21) Emita um relatório com o número de alunos matriculados nas disciplinas por departamento.
22) Emita um relatório agrupado por semestre contendo, o numero de alunos, o número de disciplinas, o numero de professores e a média de notas.
23) Emita um relatório contendo as disciplinas que cada aluno falta cursar do seu curso, contendo o nome da disciplina, a carga horária e o tipo.
24) Qual a carga horária total cursada por aluno e tipo de disciplina.