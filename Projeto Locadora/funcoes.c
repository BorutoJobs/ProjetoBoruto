#include "funcoes.h"

//AQUI DEVERÃO SER DECLARADAS TODAS AS VARIÁVEIS GLOBAIS E ESTRUTURAS QUE SERÃO UTILIZADAS


//AQUI FICA O CÓDIGO DE TODAS AS FUNÇÕES
//TODA E QUALQUER OUTRA FUNÇÃO QUE FOR USADA DENTRO DE menuPrincipal DEVERÁ SER DECLARADA ANTES DELE!


//FUNÇÃO QUE IMPRIME O SUBMENU DE LOCAÇÃO
void menuLocacao(){
	fflush(stdin);
	system("cls");
	printf("\n\n <<<<Locação>>>> \n\n");
	
	printf("\n\n1- Realizar locação");
	printf("\n\n2- Voltar");
}

//FUNÇÃO QUE IMPRIME O SUBMENU DE CLIENTE
void menuCliente(){
	fflush(stdin);
	system("cls");
	printf("\n\n <<<<Clientes>>>> \n\n");
	
	printf("\n\n1- Cadastrar novo cliente");
	printf("\n\n2- Consultar clientes cadastrados");
	printf("\n\n3- Listar todos os clientes cadastrados");
	printf("\n\n4- Voltar");
}

void menuPrincipal(){
	int opcao;
	printf("\n\n <<<<BEM VINDO A LOCACAO DE JOGOS --insira nome de verdade aqui-->>>> \n\n");
	printf(" 1- Jogos disponíveis \n\n 2- Menu de Clientes \n\n 3- Menu de Locação \n\n 4- Sair");
	printf("\n\n>");
	scanf("%d",&opcao);
	while(opcao != 4){
		switch(opcao){
			case 1:
				fflush(stdin);
				system("cls");
				printf("\n\n <<<<Lista de jogos>>>> \n\n");	
				/*AQUI DEVERÁ SER LISTADO TODOS OS JOGOS --DEFINIR QUAIS INFORMAÇÕES APARECERÃO*/
				printf("\nAperte qualquer tecla para voltar");
				getchar();	//ESPERA ALGUMA TECLA DO USUÁRIO
				break;
			case 2:			
				
				menuCliente();
				//TUDO ISSO ABAIXO FOI COLOCADO DENTRO DA FUNÇÃO, PARA EVITAR REPETIÇÃO DE CÓDIGO
				
				/*
				fflush(stdin);
				system("cls");
				printf("\n\n <<<<Clientes>>>> \n\n");
				printf("\n\n1- Cadastrar novo cliente");
				printf("\n\n2- Consultar clientes cadastrados"); 	//NA CONSULTA DEVERÁ SER FEITO A OPÇÃO DE EXCLUIR CLIENTE --DEFINIR TAMBÉM QUAIS INFORMAÇÕES IRÃO APARECER
				printf("\n\n3- Listar todos os clientes cadastrados");	//DEFINIR QUAIS INFORMAÇÕES IRÃO APARECER
				printf("\n\n4- Voltar");
				*/
				
				printf("\n\n>");
				scanf("%d", &opcao);
				while(opcao != 4){
					/*AQUI DEVERÁ SER FEITO O SUBMENU COM AS FUNCIONALIDADES DE CADA OPÇÃO*/
					
					switch(opcao){
						case 1:
							fflush(stdin);
							system("cls");
							//CADASTRO
							break;
						case 2:
							fflush(stdin);
							system("cls");
							//CONSULTA
							break;
						case 3:
							fflush(stdin);
							system("cls");
							//LISTAGEM
							break;
						default:	//DEFAULT É USADO PARA OPÇÕES INVÁLIDAS!
							fflush(stdin);
							system("cls");
							printf("\nOpção inválida!");
							getchar();
							break;			
					}										
					menuCliente();
				
					printf("\n\n>");
					scanf("%d", &opcao);
				}				
				break;
			case 3:	
				menuLocacao();
				//TUDO ISSO ABAIXO FOI COLOCADO DENTRO DA FUNÇÃO, PARA EVITAR REPETIÇÃO DE CÓDIGO
				
				/*
				fflush(stdin);
				system("cls");
				printf("\n\n <<<<Locação>>>> \n\n");
				printf("\n\n1- Realizar locação");
				printf("\n\n2- Voltar");
				*/
				
				printf("\n\n>");
				scanf("%d", &opcao);
				while(opcao != 2){
					switch(opcao){
						case 1:
							/*AQUI DEVERÁ SER FEITA A LOCAÇÃO --DEFINIR COMO IDENTIFICAR CLIENTE(LOGIN E SENHA?)*/
							fflush(stdin);
							system("cls");
							break;
						default:
							fflush(stdin);				
							system("cls");
							printf("\nOpção inválida!");
							getchar();
							break;							
					}						
					menuLocacao();
				
					printf("\n\n>");
					scanf("%d", &opcao);
				}
				break;
				
			default: //DEFAULT É USADO PARA OPÇÕES INVÁLIDAS!
				fflush(stdin);				
				system("cls");
				printf("\nOpção inválida!");
				getchar();
				break;
		}
		fflush(stdin);
		system("cls");
		printf("\n\n <<<<BEM VINDO A LOCACAO DE JOGOS --insira nome de verdade aqui-->>>> \n\n");
		printf(" 1- Jogos disponíveis \n\n 2- Menu de Clientes \n\n 3- Menu de Locação \n\n 4- Sair");
		printf("\n\n>");
		scanf("%d",&opcao);
	}
}




