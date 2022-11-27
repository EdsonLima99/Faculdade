//=============================>		EDSON LIMA  &  LAYS SANTOS		<========================//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[100];

typedef struct tipoDisciplina
{
    string nome_disciplina;
    char semestreLetivo[7];
    float nota;
    struct tipoDisciplina *ante, *prox;
} TDisciplina;

typedef struct tipoAluno
{
    string nome_aluno;
    char sexo;
    TDisciplina *disciplinas;
    struct tipoAluno *prox;
} TAluno;



typedef struct tipoTurma
{
    char nome_turma[4];
    TAluno *aluno;
    struct tipoTurma *prox;
} TTurma;

typedef struct tipoCurso
{
    string nome_curso;
    TTurma *turmas;
    struct tipoCurso *ante, *prox;
} TCurso;

typedef struct tipoLista
{
    TCurso *inicio;
    TCurso *fim;
} TLista;

TLista lista;

void inicializa(TLista *L);
void menu(TLista *L);
void opcoes(TLista *L, int d);
int menuGeral(int d);

//
void inserir(TLista *L, int d);
void inserirCurso(TLista *L);
void inserirTurma(TLista *L);
void inserirAluno(TLista *L);
void inserirDisciplina(TLista *L);

//
void listar(TLista *L, int d);
void listarCurso(TLista *L);
void listarTurma(TLista *L);
void listarAluno(TLista *L);
void listarDisciplina(TLista *L);

//
void consultar(TLista *L, int d);
void consultarCurso(TLista *L);
void consultarTurma(TLista *L);
void consultarAluno(TLista *L);
void consultarDisciplina(TLista *L);

//
void remover(TLista *L, int d);
void removerCurso(TLista *L);
void removerTurma(TLista *L);
void removerAluno(TLista *L);
void removerDisciplina(TLista *L);

// void remover(TLista *L, int d);
// void listar(TLista *L, int d);
// void consultar(TLista *L, int d);

void main()
{
    int op;

    inicializa(&lista);

    menu(&lista);
}

void inicializa(TLista *L)
{
    L->inicio = NULL;
    L->fim = NULL;
}

void menu(TLista *L)
{
    int opcao;

    do
    {
        ////system("CLS"); // Limpa a Tela e posiciona o
        //  CURSOR no canto esquerdo superior da mesma
        printf("\n\n\n\t     =====| MENU |=====\n\n");
        printf("0 - SAIR (Encerrar Aplica��o).\n\n");
        printf("1 - Cursos\n");
        printf("2 - Turmas\n");
        printf("3 - Alunos\n");
        printf("4 - Disciplinas\n");
        printf("\tInforme OPCAO desejada: ");

        scanf("%d", &opcao);

        if ((opcao > 4) || (opcao < 0))
        {
            printf("\n\n\n");
            printf("\t+-------------------------------------------------+\n");
            printf("\t|   ERRO:                                         |\n");
            printf("\t|                                                 |\n");
            printf("\t|   OPCAO INVALIDA!!!                             |\n");
            printf("\t|                                                 |\n");
            printf("\t|   Tente outra vez.                              |\n");
            printf("\t+-------------------------------------------------+\n\n");
            ////system("PAUSE");
        }
    } while ((opcao > 4) || (opcao < 0));

    switch (opcao)
    {
    case 1:
        opcoes(&lista, 1);
        break;
    case 2:
        opcoes(&lista, 2);
        break;
    case 3:
        opcoes(&lista, 3);
        break;
    case 4:
        opcoes(&lista, 4);
        break;
    default:
        break;
    } // switch
}

void opcoes(TLista *L, int d)
{
    int opc;

    do
    {
        opc = menuGeral(d);
        getchar();

        switch (opc)
        {
        case 1:
            inserir(&lista, d);
            break;
        case 2:
            remover(&lista, d);
            break;
        case 3:
            listar(&lista, d);
            break;
        case 4:
            consultar(&lista, d);
            break;
        } // switch

    } while (opc != 0);
    if (opc == 0)
        menu(&lista);
}

int menuGeral(int d)
{
    int escolha;
    //system("CLS"); // Limpa a Tela e posiciona o
    //  CURSOR no canto esquerdo superior da mesma
    if (d == 1)
    {
        printf("\n\n\n\t     =====| CURSOS |=====\n\n");
        printf("0 - retornar para menu principal.\n\n");
        printf("1 - inserir Curso.\n");
        printf("2 - excluir Curso.\n");
        printf("3 - Listar Todos os Cursos.\n");
        printf("4 - Consultar Curso por Nome.\n");
        printf("\tInforme OPCAO desejada: ");
    }
    else if (d == 2)
    {
        printf("\n\n\n\t     =====| TURMAS |=====\n\n");
        printf("0 - retornar para menu principal.\n\n");
        printf("1 - inserir Turma.\n");
        printf("2 - excluir Turma.\n");
        printf("3 - Listar Todos os Turmas.\n");
        printf("4 - Consultar Turma por Nome.\n");
        printf("\tInforme OPCAO desejada: ");
    }
    else if (d == 3)
    {
        printf("\n\n\n\t     =====| ALUNOS |=====\n\n");
        printf("0 - retornar para menu principal.\n\n");
        printf("1 - inserir Aluno.\n");
        printf("2 - excluir Aluno.\n");
        printf("3 - Listar Todos os Alunos.\n");
        printf("4 - Consultar Aluno por Nome.\n");
        printf("\tInforme OPCAO desejada: ");
    }
    else
    {
        printf("\n\n\n\t     =====| DISCIPLINAS |=====\n\n");
        printf("0 - retornar para menu principal.\n\n");
        printf("1 - inserir Disciplina.\n");
        printf("2 - excluir Disciplina.\n");
        printf("3 - Listar Todos os Disciplinas.\n");
        printf("4 - Consultar Disciplina por Nome.\n");
        printf("\tInforme OPCAO desejada: ");
    }

    scanf("%d", &escolha);

    if ((escolha > 4) || (escolha < 0))
    {
        printf("\n\n\n");
        printf("\t+-------------------------------------------------+\n");
        printf("\t|   ERRO:                                         |\n");
        printf("\t|                                                 |\n");
        printf("\t|   OPCAO INVALIDA!!!                             |\n");
        printf("\t|                                                 |\n");
        printf("\t|   Tente outra vez.                              |\n");
        printf("\t+-------------------------------------------------+\n\n");
        //system("PAUSE");
    }
    return escolha;
}

void inserir(TLista *L, int d)
{
    if (d == 1)
    {
        inserirCurso(&lista);
    }
    else if (d == 2)
    {
        inserirTurma(&lista);
    }
    else if (d == 3)
	{
        inserirAluno(&lista);
    }
    else
    {
        inserirDisciplina(&lista);
    }
}

void inserirCurso(TLista *L)
{
    TCurso *novo = (TCurso *)malloc(sizeof(TCurso));
    char *curso = (char*)calloc(40,sizeof(char));
    int inserido = 0;

    printf("\n\n\n");
    printf("\t=====| INSERE NOVO CURSO |=====\n\n");
    printf("\tInforme o NOME do CURSO: ");
    fgets(curso, sizeof(curso), stdin);

    strcpy(curso, strupr(curso));

    if (L->inicio == NULL)
    {
    	strcpy(novo->nome_curso, curso);
	    novo->ante = NULL;
	    novo->prox = NULL;
	    novo->turmas = NULL;
        // Lista VAZIA: inserir o primeiro N?.
        L->inicio = novo;
        L->fim = novo;
    }
    else
    {
        // Lista possui pelo menos um N?: Inserir dados em
        // ordem crescente.
        TCurso *atual = L->inicio;
        TCurso *previo = NULL;

        while (atual != NULL)
        {
        	if(strcmp(atual->nome_curso, curso) == 0)
        	{
        		printf("\n\tCURSO ja cadastrado\n");
        		break;
			}
			else if (strcmp(atual->nome_curso, curso) > 0 || strcmp(atual->nome_curso, curso) < 0)
            {
            	strcpy(novo->nome_curso, curso);
			    novo->ante = NULL;
			    novo->prox = NULL;
			    novo->turmas = NULL;
	    
                inserido = 1;
                novo->prox = atual;
                novo->ante = atual->ante;

                if (novo->ante == NULL)
                {
                    // Inserir novo no in?cio da Lista
                    L->inicio = novo;
                    atual->ante = novo;
                }
                else
                {
                    // Inserir novo em algum ponto no meio da Lista
                    previo = atual->ante;
                    previo->prox = novo;

                    atual->ante = novo;
                } // if else
                break;
            } // if

            atual = atual->prox; // movimenta ponteiro ATUAL para
                                 // o N? SEGUINTE.
                                 // while
	        if (!inserido)
	        {
	            // Inserir novo no final da Lista
	            L->fim->prox = novo;
	            novo->ante = L->fim;
	            L->fim = novo;
	        } // if
    	}


    } // if ... else
    //system("PAUSE");
}

void inserirTurma(TLista *L)
{
    TTurma *novo = (TTurma *)malloc(sizeof(TTurma));
    TCurso *curso = L->inicio;
    int inserido = 0, nencontrado = 1;
    string consulta;
    char turma[4];

    printf("\n\n\tInforme o nome do CURSO para consulta: ");
    fgets(consulta, sizeof(consulta), stdin);

    strcpy(consulta, strupr(consulta));

    while (curso != NULL)
    {
        if (strcmp(curso->nome_curso, consulta) == 0)
        {
            printf("\n\n\n");
            printf("\t=====| INSERIR NOVA TURMA |=====\n\n");
            printf("\tInforme o NOME da TURMA: ");
            fgets(turma, sizeof(turma), stdin);

            strcpy(turma, strupr(turma));

            if (curso->turmas == NULL)
            {
            	strcpy(novo->nome_turma, turma);
	            novo->prox = NULL;
	            novo->aluno = NULL;
                // Lista VAZIA: inserir o primeiro N?.
                curso->turmas = novo;
            }
            else
            {
                // Lista possui pelo menos um N?: Inserir dados em
                // ordem crescente.
                TTurma *atual = curso->turmas;
                TTurma *previo = NULL;

                while (atual != NULL)
                {
                	if (strcmp(atual->nome_turma, turma) == 0)
                	{
                		printf("\n\tTURMA ja cadastrada\n");
                		break;
					}
                    else if (strcmp(atual->nome_turma, turma) > 0 || strcmp(atual->nome_turma, turma) < 0)
                    {
						strcpy(novo->nome_turma, turma);
			            novo->prox = NULL;
			            novo->aluno = NULL;
                        inserido = 1;
                        novo->prox = atual;

                        if (previo == NULL)
                        {
                            // Inserir novo no in?cio da Lista
                            curso->turmas = novo;
                        }
                        else
                        {
                            // Inserir novo em algum ponto no meio da Lista
                            previo->prox = novo;
                        } // if else
                        break;
                    } // if
                    previo = atual;
                    atual = atual->prox; // movimenta ponteiro ATUAL para
                                         // o N? SEGUINTE.
                                         // while

	                if (!inserido)
	                {
	                    // Inserir novo no final da Lista
	                    previo->prox = novo;
	                } // if
            	}

            } // if ... else
            nencontrado = 0;
        }
        curso = curso->prox;
    } // while

    if (nencontrado)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  CURSO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
        // //system("PAUSE");
    }
     //system("PAUSE");
}

void inserirAluno(TLista *L)
{
	TAluno *novo = (TAluno *)malloc(sizeof(TAluno));
    TCurso *curso = L->inicio;
    TTurma *turma = curso->turmas;
    int inserido = 0, nencontradoCurso = 1;
    int nencontradoTurma = 1;
    string consultaCurso, aluno;
	char consultaTurma[4], gen;

    printf("\n\n\tInforme o nome do CURSO para consulta: ");
    fgets(consultaCurso, sizeof(consultaCurso), stdin);

    strcpy(consultaCurso, strupr(consultaCurso));

	while (curso != NULL)
    {
        if (strcmp(curso->nome_curso, consultaCurso) == 0)
        {
        	
		    printf("\n\n\tInforme o nome da TURMA para consulta: ");
		    fgets(consultaTurma, sizeof(consultaTurma), stdin);
		    
		    strcpy(consultaTurma, strupr(consultaTurma));
		    
            while (turma != NULL)
            {
                if (strcmp(turma->nome_turma, consultaTurma) == 0)
                {
                	fflush(stdin);
                    printf("\n\n\n");
		            printf("\t=====| INSERIR NOVO ALUNO |=====\n\n");
		            printf("\tInforme o NOME do ALUNO: ");
		            fgets(aluno, sizeof(aluno), stdin);
		            
		            do{
					    printf("\tInforme o SEXO (M ou F): ");
					    scanf(" %c", &(gen));
					}while(gen != 'F' && gen != 'M');
		
					strcpy(aluno, strupr(aluno));
					
		            if (turma->aluno == NULL)
		            {
			            strcpy(aluno, strupr(aluno));
			            novo->prox = NULL;
			            novo->disciplinas = NULL;
		                // Lista VAZIA: inserir o primeiro N?.
		                turma->aluno = novo;
		            }
		            else
		            {
		                // Lista possui pelo menos um N?: Inserir dados em
		                // ordem crescente.
		                TAluno *atual = turma->aluno;
		                TAluno *previo = NULL;
		
		                while (atual != NULL)
		                {
		                    if (strcmp(atual->nome_aluno, aluno) > 0 || strcmp(atual->nome_aluno, aluno) < 0)
		                    {
		                    	strcpy(aluno, strupr(aluno));
					            novo->prox = NULL;
					            novo->disciplinas = NULL;
		                        inserido = 1;
		                        novo->prox = atual;
		
		                        if (previo == NULL)
		                        {
		                            // Inserir novo no in?cio da Lista
		                            turma->aluno = novo;
		                        }
		                        else
		                        {
		                            // Inserir novo em algum ponto no meio da Lista
		                            previo->prox = novo;
		                        } // if else
		                        break;
		                    } // if
		                    previo = atual;
		                    atual = atual->prox; // movimenta ponteiro ATUAL para
		                                         // o N? SEGUINTE.
		                                         // while
		
			                if (!inserido)
			                {
			                    // Inserir novo no final da Lista
			                    previo->prox = novo;
			                } // if
		            	}
		            }
                    nencontradoTurma = 0;
                }
                turma = turma->prox;
            }
            nencontradoCurso = 0;
        }
        curso = curso->prox;
        if (curso != NULL)
        {
            turma = curso->turmas;
        }
    } // while
    if (nencontradoCurso)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  CURSO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }

    if (nencontradoTurma)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  TURMA NAO ENCONTRADA!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    //system("PAUSE");
}

void inserirDisciplina(TLista *L)
{
	TDisciplina *novo = (TDisciplina *)malloc(sizeof(TDisciplina));
    TCurso *curso = L->inicio;
    TTurma *turma = curso->turmas;
    TAluno *aluno = turma->aluno;
    int inserido = 0, nencontradoCurso = 1;
    int nencontradoTurma = 1, nencontradoAluno = 1;
    string consultaCurso, consultaAluno, disciplina;
	char consultaTurma[4], semestre[7];
	float nota;

    printf("\n\n\tInforme o nome do CURSO para consulta: ");
    fgets(consultaCurso, sizeof(consultaCurso), stdin);

    strcpy(consultaCurso, strupr(consultaCurso));

	while (curso != NULL)
    {
        if (strcmp(curso->nome_curso, consultaCurso) == 0)
        {
		    printf("\n\n\tInforme o nome da TURMA para consulta: ");
		    fgets(consultaTurma, sizeof(consultaTurma), stdin);
		    
		    strcpy(consultaTurma, strupr(consultaTurma));
		    
            while (turma != NULL)
            {
                if (strcmp(turma->nome_turma, consultaTurma) == 0)
                {
		            fflush(stdin);
                	printf("\n\n\tInforme o nome do ALUNO para consulta: ");
				    fgets(consultaAluno, sizeof(consultaAluno), stdin);
				    
				    strcpy(consultaAluno, strupr(consultaAluno));
				    
                	while(aluno != NULL)
                	{
                		if(strcmp(aluno->nome_aluno, consultaAluno) == 0)
                		{
		                	fflush(stdin);
		                    printf("\n\n\n");
				            printf("\t=====| INSERIR NOVA DISCIPLINA |=====\n\n");
				            printf("\tInforme o NOME da DISCIPLINA: ");
				            fgets(disciplina, sizeof(disciplina), stdin);
				            
				            printf("\tInforme o SEMESTRE LETIVO da DISCIPLINA: ");
				            fgets(semestre, sizeof(semestre), stdin);
				            
				            printf("\tInforme a NOTA na DISCIPLINA: ");
				            scanf("%f", &(nota));
				
				            strcpy(disciplina, strupr(disciplina));
				
				            if (aluno->disciplinas == NULL)
				            {
				            	strcpy(novo->nome_disciplina, disciplina);
				            	strcpy(novo->semestreLetivo, semestre);
				            	novo->nota = nota;
					            novo->ante = NULL;
					            novo->prox = NULL;
				                // Lista VAZIA: inserir o primeiro N?.
				                aluno->disciplinas = novo;
				            }
				            else
				            {
				                // Lista possui pelo menos um N?: Inserir dados em
				                // ordem crescente.
				                TDisciplina *atual = aluno->disciplinas;
				                TDisciplina *previo = NULL;
				
				                while (atual != NULL)
				                {
				                	if((strcmp(atual->nome_disciplina, novo->nome_disciplina)) == 0 && (strcmp(atual->semestreLetivo, novo->semestreLetivo) == 0))
				                	{
			                			printf("\n\tDISCIPLINA ja cadastrada\n");
			                			break;
									}
				                    else if ((strcmp(atual->nome_disciplina, disciplina) > 0) || (strcmp(atual->nome_disciplina, disciplina) < 0) || (strcmp(atual->semestreLetivo, novo->semestreLetivo) == 1))
				                    {
				                    	strcpy(novo->nome_disciplina, disciplina);
						            	strcpy(novo->semestreLetivo, semestre);
						            	novo->nota = nota;
							            novo->ante = NULL;
							            novo->prox = NULL;
				                        inserido = 1;
				                        novo->prox = atual;
				                        novo->ante = atual->ante;
				
				                        if (novo->ante == NULL)
				                        {
				                            // Inserir novo no in?cio da Lista
				                            aluno->disciplinas = novo;
				                            atual->ante = novo;
				                        }
				                        else
				                        {
				                            // Inserir novo em algum ponto no meio da Lista
				                            previo = atual->ante;
				                            previo->prox = novo;
				                            
				                            atual->ante = novo;
				                        } // if else
				                        break;
				                    } // if
				                    atual = atual->prox; // movimenta ponteiro ATUAL para
				                                         // o N? SEGUINTE.
				                                         // while
				
					                if (!inserido)
					                {
					                    // Inserir novo no final da Lista
					                    previo->prox = novo;
					                    novo->ante = novo;
					                } // if
				            	}
				            }
				            nencontradoAluno = 0;
		                }
		                aluno = aluno->prox;
					}
		            nencontradoTurma = 0;
                }
                turma = turma->prox;
                if(turma != NULL)
                	aluno = turma->aluno;
            }
            nencontradoCurso = 0;
        }
        curso = curso->prox;
        if (curso != NULL)
        {
            turma = curso->turmas;
            aluno = turma->aluno;
        }
    } // while
    if (nencontradoCurso)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  CURSO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }

    if (nencontradoTurma)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  TURMA NAO ENCONTRADA!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    if (nencontradoAluno)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  ALUNO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    //system("PAUSE");
}

void remover(TLista *L, int d)
{
    if (d == 1)
    {
        removerCurso(&lista);
    }
    else if (d == 2)
    {
        removerTurma(&lista);
    }
    else if (d == 3)
    {
        removerAluno(&lista);
    }
    else
    {
        removerDisciplina(&lista);
    }
}

void removerCurso(TLista *L)
{
    TCurso *atual = L->inicio, *previo = NULL, *proximo = NULL;
    string parametro;
    int removido = 0;

    printf("\n\n\t=====| REMOVER CURSO |=====\n\n");
    printf("\tInforme o CURSO a ser REMOVIDO: ");
    fgets(parametro, sizeof(parametro), stdin);

    strcpy(parametro, strupr(parametro));
    while (atual != NULL)
    {
        if (strcmp(atual->nome_curso, parametro) == 0)
        {
            proximo = atual->prox;
            previo = atual->ante;

            if (previo == NULL)
            {
                L->inicio = proximo;
                if (proximo != NULL)
                    proximo->ante = NULL;
                if (atual == L->fim)
                    L->fim = NULL;
            }
            else
            {
                previo->prox = proximo;
                if (proximo != NULL)
                {
                    proximo->ante = previo;
                }
                else
                {
                    L->fim = previo;
                }
            }

            free(atual);
            removido = 1;
            break;
        } // if

        atual = atual->prox;

    } // while

    if (removido)
    {
        printf("\n\n\n");
        printf("\t+-----------------------------------------+\n");
        printf("\t|  AVISO:                                 |\n");
        printf("\t|                                         |\n");
        printf("\t|  CURSO REMOVIDO com SUCESSO !!!         |\n");
        printf("\t|                                         |\n");
        printf("\t+-----------------------------------------+\n\n\n");
        ////system("PAUSE");
    }
    else
    {
        printf("\n\n\n");
        printf("\t+-----------------------------------------+\n");
        printf("\t|  ALERTA:                                |\n");
        printf("\t|                                         |\n");
        printf("\t|  CURSO NAO ENCONTRADO e nem REMOVIDO!!! |\n");
        printf("\t|                                         |\n");
        printf("\t+-----------------------------------------+\n\n\n");
        ////system("PAUSE");
    }
    //system("PAUSE");
}

void removerTurma(TLista *L)
{
    TCurso *curso = L->inicio;
    TTurma *atual = curso->turmas, *previo = NULL, *proximo = NULL;
    string consultaCurso;
    char parametro[4];
    int removido = 0, nencontradoCurso = 1;
    
    printf("\n\n\tInforme o nome do CURSO para consulta: ");
    fgets(consultaCurso, sizeof(consultaCurso), stdin);

    
    printf("\n\n\t=====| REMOVER TURMA |=====\n\n");
    printf("\tInforme a TURMA a ser REMOVIDA: ");
    fgets(parametro, sizeof(parametro), stdin);


    strcpy(consultaCurso, strupr(consultaCurso));
    strcpy(parametro, strupr(parametro));

    while (curso != NULL)
    {
    	if(strcmp(curso->nome_curso, consultaCurso)==0)
    	{
	        while (atual != NULL)
	        {
	            if (strcmp(atual->nome_turma, parametro) == 0)
	            {
	                proximo = atual->prox;
	
	                if (previo == NULL)
	                {
	                    curso->turmas = proximo;
	                }
	                else
	                {
	                    previo->prox = proximo;
	                }
	                free(atual);
	                removido = 1;
	                break;
	            } // if
	            previo = atual;
	            atual = atual->prox;
	            if (atual != NULL)
	                proximo = atual->prox;
	            else
	                proximo = NULL;
	        }
	        nencontradoCurso = 0;
    	}
		curso = curso->prox;
        if (curso != NULL)
        {
            atual = curso->turmas;
            previo = NULL;
            proximo = NULL;
        }
    } // while
    
    if (nencontradoCurso)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  CURSO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    
    if (removido)
    {
        printf("\n\n\n");
        printf("\t+-----------------------------------------+\n");
        printf("\t|  AVISO:                                 |\n");
        printf("\t|                                         |\n");
        printf("\t|  TURMA REMOVIDA com SUCESSO !!!         |\n");
        printf("\t|                                         |\n");
        printf("\t+-----------------------------------------+\n\n\n");
    }
    else
    {
        printf("\n\n\n");
        printf("\t+-----------------------------------------+\n");
        printf("\t|  ALERTA:                                |\n");
        printf("\t|                                         |\n");
        printf("\t|  TURMA NAO ENCONTRADA e nem REMOVIDA!!! |\n");
        printf("\t|                                         |\n");
        printf("\t+-----------------------------------------+\n\n\n");
    }
    //system("PAUSE");
}

void removerAluno(TLista *L)
{
	TCurso *curso = L->inicio;
    TTurma *turma = curso->turmas;
	TAluno *atual = turma->aluno, *previo = NULL, *proximo = NULL;
    string parametro, consultaCurso;
    char consultaTurma[4];
    int removido = 0, nencontradoCurso =1, nencontradoTurma =1;

	printf("\n\n\tInforme o nome do CURSO para consulta: ");
    fgets(consultaCurso, sizeof(consultaCurso), stdin);

    printf("\n\n\tInforme o nome da TURMA para consulta: ");
    fgets(consultaTurma, sizeof(consultaTurma), stdin);
    
    
    printf("\n\n\t=====| REMOVER ALUNO |=====\n\n");
    fflush(stdin);
    printf("\tInforme o ALUNO a ser REMOVIDO: ");
    fgets(parametro, sizeof(parametro), stdin);


    strcpy(parametro, strupr(parametro));
    strcpy(consultaCurso, strupr(consultaCurso));
    strcpy(consultaTurma, strupr(consultaTurma));

    while (curso != NULL)
    {
    	if(strcmp(curso->nome_curso, consultaCurso)==0)
    	{
	        while (turma != NULL)
	        {
	        	if(strcmp(turma->nome_turma, consultaTurma)==0)
	        	{
		        	while(atual!= NULL)
		        	{
			            if (strcmp(atual->nome_aluno, parametro) == 0)
			            {
			                proximo = atual->prox;
			
			                if (previo == NULL)
			                {
			                    turma->aluno = proximo;
			                }
			                else
			                {
			                    previo->prox = proximo;
			                }
			                free(atual);
			                removido = 1;
			                break;
			            } // if
			            previo = atual;
			            atual = atual->prox;
			            if (atual != NULL)
			                proximo = atual->prox;
			            else
			                proximo = NULL;
			        }
			        nencontradoTurma=0;
				}
				turma = turma->prox;
		        if(turma != NULL)
		        {
		        	atual = turma->aluno;
		        	previo = NULL;
		        	proximo = NULL;
				}
	        }
	        nencontradoCurso=0;
    	}
        curso = curso->prox;
        if (curso != NULL)
        {
            turma = curso->turmas;
            atual = turma->aluno;
            previo = NULL;
            proximo = NULL;
        }
    } // while
    
    if (nencontradoCurso)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  CURSO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
	if (nencontradoTurma)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  TURMA NAO ENCONTRADA!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    
    if (removido)
    {
        printf("\n\n\n");
        printf("\t+-----------------------------------------+\n");
        printf("\t|  AVISO:                                 |\n");
        printf("\t|                                         |\n");
        printf("\t|  ALUNO REMOVIDO com SUCESSO !!!         |\n");
        printf("\t|                                         |\n");
        printf("\t+-----------------------------------------+\n\n\n");
    }
    else
    {
        printf("\n\n\n");
        printf("\t+-----------------------------------------+\n");
        printf("\t|  ALERTA:                                |\n");
        printf("\t|                                         |\n");
        printf("\t|  ALUNO NAO ENCONTRADO e nem REMOVIDO!!! |\n");
        printf("\t|                                         |\n");
        printf("\t+-----------------------------------------+\n\n\n");
    }
    //system("PAUSE");
}

void removerDisciplina(TLista *L)
{
	TCurso *curso = L->inicio;
    TTurma *turma = curso->turmas;
	TAluno *aluno = turma->aluno;
	TDisciplina *atual = aluno->disciplinas, *previo = NULL, *proximo = NULL;
    string parametro, consultaCurso, consultaAluno;
    char consultaTurma[4];
    int removido = 0;
    int nencontradoCurso=1, nencontradoTurma=1, nencontradoAluno=1;
    
    printf("\n\n\tInforme o nome do CURSO para consulta: ");
    fgets(consultaCurso, sizeof(consultaCurso), stdin);

    printf("\n\n\tInforme o nome da TURMA para consulta: ");
    fgets(consultaTurma, sizeof(consultaTurma), stdin);
    
    fflush(stdin);
    printf("\n\n\tInforme o nome do ALUNO para consulta: ");
    fgets(consultaAluno, sizeof(consultaAluno), stdin);

    
    printf("\n\n\t=====| REMOVER TURMA |=====\n\n");
    fflush(stdin);
    printf("\tInforme a DISCIPLINA a ser REMOVIDA: ");
    fgets(parametro, sizeof(parametro), stdin);


    strcpy(parametro, strupr(parametro));
    strcpy(consultaCurso, strupr(consultaCurso));
    strcpy(consultaTurma, strupr(consultaTurma));
    strcpy(consultaAluno, strupr(consultaAluno));

    while (curso != NULL)
    {
    	if(strcmp(curso->nome_curso, consultaCurso)==0)
    	{
	        while (turma != NULL)
	        {
	        	if(strcmp(turma->nome_turma, consultaTurma)==0)
	        	{
		        	while(aluno!= NULL)
		        	{
		        		if(strcmp(aluno->nome_aluno, consultaAluno)==0)
		        		{
			            	while(atual != NULL)
			            	{
			            		if(strcmp(atual->nome_disciplina, parametro) == 0)
			            		{
					                proximo = atual->prox;
					                previo = atual->ante;
					
					                if (previo == NULL)
					                {
					                    aluno->disciplinas = proximo;
					                    if (proximo != NULL)
			                    			proximo->ante = NULL;
					                }
					                else
					                {
					                    previo->prox = proximo;
					                }
					                free(atual);
					                removido = 1;
					                break;
								} // if
								atual = atual->prox;
							}
							nencontradoAluno = 0;
						}
						aluno = aluno->prox;
						if(aluno != NULL)
						{
							atual =aluno->disciplinas;
							previo = NULL;
							proximo = NULL;
						}
			        }
			        
					nencontradoTurma = 0;
				}
				turma = turma->prox;
		        if(turma != NULL)
		        {
		        	aluno = turma->aluno;
		        	previo = NULL;
		        	proximo = NULL;
				}
	        }
	        
	        nencontradoCurso = 0;
    	}
		curso = curso->prox;
        if (curso != NULL)
        {
            turma = curso->turmas;
            aluno = turma->aluno;
            atual = aluno->disciplinas;
            previo = NULL;
            proximo = NULL;
        }
    } // while
    
    if (nencontradoCurso)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  CURSO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    if (nencontradoTurma)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  TURMA NAO ENCONTRADA!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }if (nencontradoAluno)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  ALUNO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    
    if (removido)
    {
        printf("\n\n\n");
        printf("\t+---------------------------------------+\n");
        printf("\t|  AVISO:                               |\n");
        printf("\t|                                       |\n");
        printf("\t|  DISCIPLINA REMOVIDA com SUCESSO !!!  |\n");
        printf("\t|                                       |\n");
        printf("\t+---------------------------------------+\n\n\n");
    }
    else
    {
        printf("\n\n\n");
        printf("\t+----------------------------------------------+\n");
        printf("\t|  ALERTA:                                     |\n");
        printf("\t|                                              |\n");
        printf("\t|  DISCIPLINA NAO ENCONTRADA e nem REMOVIDA!!! |\n");
        printf("\t|                                              |\n");
        printf("\t+----------------------------------------------+\n\n\n");
    }
    //system("PAUSE");	
}

void listar(TLista *L, int d)
{
    if (d == 1)
    {
        listarCurso(&lista);
    }
    else if (d == 2)
    {
        listarTurma(&lista);
    }
    else if (d == 3)
    {
        listarAluno(&lista);
    }
    else
    {
        listarDisciplina(&lista);
    }
}

void exibeCurso(TCurso *atual)
{
    printf("\n\t+-------------------+");
    printf("\n\tCurso: %s\n", atual->nome_curso);
}

void exibeTurma(TTurma *atual)
{
    printf("\n\t\t+-------------------+");
    printf("\n\t\tTurma: %s\n", atual->nome_turma);
}

void exibeAluno(TAluno *atual)
{
    printf("\n\t\t\t+-------------------+");
    printf("\n\t\t\tAluno: %s", atual->nome_aluno);
    printf("\n\t\t\tSexo: %c\n", atual->sexo);
}

void exibeDisciplina(TDisciplina *atual)
{
    printf("\n\t\t\t\t+-------------------+");
    printf("\n\t\t\t\tDisciplina: %s", atual->nome_disciplina);
    printf("\n\t\t\t\tSemestre Letivo: %s", atual->semestreLetivo);
    printf("\n\t\t\t\tNota: %.2f\n", atual->nota);
}

void listarCurso(TLista *L)
{
    TCurso *atual = L->inicio;

    printf("\n\n\n");
    printf("\t=====| EXIBE LISTA COMPLETA |=====\n\n");

    while (atual != NULL)
    {
        exibeCurso(atual);
        atual = atual->prox;
    } // while
    //system("PAUSE");
}

void listarTurma(TLista *L)
{
    TCurso *curso = L->inicio;
    TTurma *atual = curso->turmas;

    printf("\n\n\n");
    printf("\t=====| EXIBE LISTA COMPLETA |=====\n\n");

    while (curso != NULL)
    {
        exibeCurso(curso);
        while (atual != NULL)
        {
            exibeTurma(atual);
            atual = atual->prox;
        }
        printf("\n");
        curso = curso->prox;
        if (curso != NULL)
        {
            atual = curso->turmas;
        }
    } // while
    //system("PAUSE");
}

void listarAluno(TLista *L)
{
	TCurso *curso = L->inicio;
	TTurma *turma = curso->turmas;
	TAluno *atual = turma->aluno;
	
	printf("\n\n\n");
    printf("\t=====| EXIBE LISTA COMPLETA |=====\n\n");

    while (curso != NULL)
    {
        exibeCurso(curso);
        while (turma != NULL)
        {
            exibeTurma(turma);
            while(atual != NULL){
            	exibeAluno(atual);
            	atual = atual->prox;
			}
			turma = turma->prox;
			if(turma != NULL)
				atual = turma->aluno;
        }
        printf("\n\n");
        curso = curso->prox;
        if (curso != NULL)
        {
            turma = curso->turmas;
            atual = turma->aluno;
        }
    } // while
    //system("PAUSE");
}

void listarDisciplina(TLista *L)
{
	TCurso *curso = L->inicio;
	TTurma *turma = curso->turmas;
	TAluno *aluno = turma->aluno;
	TDisciplina *atual = aluno->disciplinas;
	
	printf("\n\n\n");
    printf("\t=====| EXIBE LISTA COMPLETA |=====\n\n");

    while (curso != NULL)
    {
        exibeCurso(curso);
        while (turma != NULL)
        {
            exibeTurma(turma);
            while(aluno != NULL)
			{
            	exibeAluno(aluno);
            	while(atual != NULL)
            	{
            		exibeDisciplina(atual);
            		atual = atual->prox;
				}
				aluno = aluno->prox;
				if(aluno != NULL)
					atual = aluno->disciplinas;
			}
			turma = turma->prox;
			if(turma != NULL)
			{
				aluno = turma->aluno;
				atual = aluno->disciplinas;
			}
        }
        printf("\n\n");
        curso = curso->prox;
        if (curso != NULL)
        {
            turma = curso->turmas;
            aluno = turma->aluno;
            atual = aluno->disciplinas;
        }
    } // while
    //system("PAUSE");
}

void consultar(TLista *L, int d)
{
    if (d == 1)
    {
        consultarCurso(&lista);
    }
    else if (d == 2)
    {
        consultarTurma(&lista);
    }
    else if (d == 3)
    {
        consultarAluno(&lista);
    }
    else
    {
        consultarDisciplina(&lista);
    }
}

void consultarCurso(TLista *L)
{
    TCurso *atual = L->inicio;
    string consulta;
    int nencontrado = 1;

    printf("\n\n\tInforme o nome do CURSO para consulta: ");
    fgets(consulta, sizeof(consulta), stdin);

    strcpy(consulta, strupr(consulta));

    printf("\n\n\n");
    printf("\t=====| EXIBE CONSULTA |=====\n\n");

    while (atual != NULL)
    {
        if (strcmp(atual->nome_curso, consulta) == 0)
        {
            exibeCurso(atual);
            nencontrado = 0;
        }
        atual = atual->prox;
    } // while

    if (nencontrado)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  CURSO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    //system("PAUSE");
}

void consultarTurma(TLista *L)
{
    TCurso *curso = L->inicio;
    TTurma *atual = curso->turmas;
    string consultaCurso;
	char consultaTurma[4];
    int nencontradoCurso = 1, nencontradoTurma = 1;

    printf("\n\n\tInforme o nome do CURSO para consulta: ");
    fgets(consultaCurso, sizeof(consultaCurso), stdin);

    printf("\n\n\tInforme o nome da TURMA para consulta: ");
    fgets(consultaTurma, sizeof(consultaTurma), stdin);

    strcpy(consultaCurso, strupr(consultaCurso));
    strcpy(consultaTurma, strupr(consultaTurma));

    printf("\n\n\n");
    printf("\t=====| EXIBE CONSULTA |=====\n\n");

    while (curso != NULL)
    {
        if (strcmp(curso->nome_curso, consultaCurso) == 0)
        {
            while (atual != NULL)
            {
                if (strcmp(atual->nome_turma, consultaTurma) == 0)
                {
                    exibeCurso(curso);
                    exibeTurma(atual);
                    nencontradoTurma = 0;
                }
                atual = atual->prox;
            }
            nencontradoCurso = 0;
        }
        curso = curso->prox;
        if (curso != NULL)
        {
            atual = curso->turmas;
        }
    } // while

    if (nencontradoCurso)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  CURSO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }

    if (nencontradoTurma)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  TURMA NAO ENCONTRADA!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    //system("PAUSE");
}

void consultarAluno(TLista *L)
{
	TCurso *curso = L->inicio;
    TTurma *turma = curso->turmas;
    TAluno *atual = turma->aluno;
    string consultaCurso, consultaAluno;
	char consultaTurma[4];
    int nencontradoCurso = 1, nencontradoTurma = 1, nencontradoAluno = 1;

    printf("\n\n\tInforme o nome do CURSO para consulta: ");
    fgets(consultaCurso, sizeof(consultaCurso), stdin);

    printf("\n\n\tInforme o nome da TURMA para consulta: ");
    fgets(consultaTurma, sizeof(consultaTurma), stdin);
    
    fflush(stdin);
    printf("\n\n\tInforme o nome do ALUNO para consulta: ");
    fgets(consultaAluno, sizeof(consultaAluno), stdin);

    strcpy(consultaCurso, strupr(consultaCurso));
    strcpy(consultaTurma, strupr(consultaTurma));
    strcpy(consultaAluno, strupr(consultaAluno));

    printf("\n\n\n");
    printf("\t=====| EXIBE CONSULTA |=====\n\n");

    while (curso != NULL)
    {
        if (strcmp(curso->nome_curso, consultaCurso) == 0)
        {
            while (turma != NULL)
            {
                if (strcmp(turma->nome_turma, consultaTurma) == 0)
                {
                	while(atual != NULL)
					{
                		if(strcmp(atual->nome_aluno, consultaAluno) == 0)
                		{
		                    exibeCurso(curso);
		                    exibeTurma(turma);
		                    exibeAluno(atual);
		                    nencontradoAluno = 0;
						}
                		atual = atual->prox;
					}
		            nencontradoTurma = 0;
                }
                turma = turma->prox;
                if(turma != NULL)
                	atual = turma->aluno;
            }
            nencontradoCurso = 0;
        }
        curso = curso->prox;
        if (curso != NULL)
        {
            turma = curso->turmas;
            atual = turma->aluno;
        }
    } // while

    if (nencontradoCurso)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  CURSO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }

    if (nencontradoTurma)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  TURMA NAO ENCONTRADA!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    if (nencontradoAluno)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  ALUNO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    //system("PAUSE");
}

void consultarDisciplina(TLista *L)
{
	TCurso *curso = L->inicio;
    TTurma *turma = curso->turmas;
    TAluno *aluno = turma->aluno;
    TDisciplina *atual = aluno->disciplinas;
    string consultaCurso, consultaAluno,  consultaDisciplina;
	char consultaTurma[4];
    int nencontradoCurso = 1, nencontradoTurma = 1, nencontradoAluno = 1, nencontradoDisciplina = 1;

    printf("\n\n\tInforme o nome do CURSO para consulta: ");
    fgets(consultaCurso, sizeof(consultaCurso), stdin);

    printf("\n\n\tInforme o nome da TURMA para consulta: ");
    fgets(consultaTurma, sizeof(consultaTurma), stdin);
    
    fflush(stdin);
    printf("\n\n\tInforme o nome do ALUNO para consulta: ");
    fgets(consultaAluno, sizeof(consultaAluno), stdin);
    
    fflush(stdin);
    printf("\n\n\tInforme o nome da DISCIPLINA para consulta: ");
    fgets(consultaDisciplina, sizeof(consultaDisciplina), stdin);

    strcpy(consultaCurso, strupr(consultaCurso));
    strcpy(consultaTurma, strupr(consultaTurma));
    strcpy(consultaAluno, strupr(consultaAluno));
    strcpy(consultaDisciplina, strupr(consultaDisciplina));

    printf("\n\n\n");
    printf("\t=====| EXIBE CONSULTA |=====\n\n");

    while (curso != NULL)
    {
        if (strcmp(curso->nome_curso, consultaCurso) == 0)
        {
            while (turma != NULL)
            {
                if (strcmp(turma->nome_turma, consultaTurma) == 0)
                {
                	while(aluno != NULL)
					{
                		if(strcmp(aluno->nome_aluno, consultaAluno) == 0)
                		{
                			while(atual != NULL)
                			{
                				if(strcmp(atual->nome_disciplina, consultaDisciplina) == 0)
                				{
				                    exibeCurso(curso);
				                    exibeTurma(turma);
				                    exibeAluno(aluno);
				                    exibeDisciplina(atual);
				                    nencontradoDisciplina = 0;
								}
								atual = atual->prox;
							}
				            nencontradoAluno = 0;
						}
                		aluno = aluno->prox;
                		if(aluno != NULL)
                			atual = aluno->disciplinas;
					}
		            nencontradoTurma = 0;
                }
                turma = turma->prox;
                if(turma != NULL)
                	aluno = turma->aluno;
            }
            nencontradoCurso = 0;
        }
        curso = curso->prox;
        if (curso != NULL)
        {
            turma = curso->turmas;
            aluno = turma->aluno;
            atual = aluno->disciplinas;
        }
    } // while

    if (nencontradoCurso)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  CURSO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }

    if (nencontradoTurma)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  TURMA NAO ENCONTRADA!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    if (nencontradoAluno)
    {
        printf("\n\n\n");
        printf("\t+--------------------------+\n");
        printf("\t|  ALERTA:                 |\n");
        printf("\t|                          |\n");
        printf("\t|  ALUNO NAO ENCONTRADO!!! |\n");
        printf("\t|                          |\n");
        printf("\t+--------------------------+\n\n\n");
    }
    
    if (nencontradoDisciplina)
    {
        printf("\n\n\n");
        printf("\t+-------------------------------+\n");
        printf("\t|  ALERTA:                      |\n");
        printf("\t|                               |\n");
        printf("\t|  DISCIPLINA NAO ENCONTRADA!!! |\n");
        printf("\t|                               |\n");
        printf("\t+-------------------------------+\n\n\n");
    }
    //system("PAUSE");
}
