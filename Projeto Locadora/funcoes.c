#include "funcoes.h"

//AQUI DEVER�O SER DECLARADAS TODAS AS VARI�VEIS GLOBAIS E ESTRUTURAS QUE SER�O UTILIZADAS


//AQUI FICA O C�DIGO DE TODAS AS FUN��ES
//TODA E QUALQUER OUTRA FUN��O QUE FOR USADA DENTRO DE menuPrincipal DEVER� SER DECLARADA ANTES DELE!


//FUN��O QUE IMPRIME O SUBMENU DE LOCA��O
void menuLocacao(){
	fflush(stdin);
	system("cls");
	printf("\n\n <<<<Loca��o>>>> \n\n");
	
	printf("\n\n1- Realizar loca��o");
	printf("\n\n2- Voltar");
}

//FUN��O QUE IMPRIME O SUBMENU DE CLIENTE
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
	printf(" 1- Jogos dispon�veis \n\n 2- Menu de Clientes \n\n 3- Menu de Loca��o \n\n 4- Sair");
	printf("\n\n>");
	scanf("%d",&opcao);
	while(opcao != 4){
		switch(opcao){
			case 1:
				fflush(stdin);
				system("cls");
				printf("\n\n <<<<Lista de jogos>>>> \n\n");	
				/*AQUI DEVER� SER LISTADO TODOS OS JOGOS --DEFINIR QUAIS INFORMA��ES APARECER�O*/
				printf("\nAperte qualquer tecla para voltar");
				getchar();	//ESPERA ALGUMA TECLA DO USU�RIO
				break;
			case 2:			
				
				menuCliente();
				//TUDO ISSO ABAIXO FOI COLOCADO DENTRO DA FUN��O, PARA EVITAR REPETI��O DE C�DIGO
				
				/*
				fflush(stdin);
				system("cls");
				printf("\n\n <<<<Clientes>>>> \n\n");
				printf("\n\n1- Cadastrar novo cliente");
				printf("\n\n2- Consultar clientes cadastrados"); 	//NA CONSULTA DEVER� SER FEITO A OP��O DE EXCLUIR CLIENTE --DEFINIR TAMB�M QUAIS INFORMA��ES IR�O APARECER
				printf("\n\n3- Listar todos os clientes cadastrados");	//DEFINIR QUAIS INFORMA��ES IR�O APARECER
				printf("\n\n4- Voltar");
				*/
				
				printf("\n\n>");
				scanf("%d", &opcao);
				while(opcao != 4){
					/*AQUI DEVER� SER FEITO O SUBMENU COM AS FUNCIONALIDADES DE CADA OP��O*/
					
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
						default:	//DEFAULT � USADO PARA OP��ES INV�LIDAS!
							fflush(stdin);
							system("cls");
							printf("\nOp��o inv�lida!");
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
				//TUDO ISSO ABAIXO FOI COLOCADO DENTRO DA FUN��O, PARA EVITAR REPETI��O DE C�DIGO
				
				/*
				fflush(stdin);
				system("cls");
				printf("\n\n <<<<Loca��o>>>> \n\n");
				printf("\n\n1- Realizar loca��o");
				printf("\n\n2- Voltar");
				*/
				
				printf("\n\n>");
				scanf("%d", &opcao);
				while(opcao != 2){
					switch(opcao){
						case 1:
							/*AQUI DEVER� SER FEITA A LOCA��O --DEFINIR COMO IDENTIFICAR CLIENTE(LOGIN E SENHA?)*/
							fflush(stdin);
							system("cls");
							break;
						default:
							fflush(stdin);				
							system("cls");
							printf("\nOp��o inv�lida!");
							getchar();
							break;							
					}						
					menuLocacao();
				
					printf("\n\n>");
					scanf("%d", &opcao);
				}
				break;
				
			default: //DEFAULT � USADO PARA OP��ES INV�LIDAS!
				fflush(stdin);				
				system("cls");
				printf("\nOp��o inv�lida!");
				getchar();
				break;
		}
		fflush(stdin);
		system("cls");
		printf("\n\n <<<<BEM VINDO A LOCACAO DE JOGOS --insira nome de verdade aqui-->>>> \n\n");
		printf(" 1- Jogos dispon�veis \n\n 2- Menu de Clientes \n\n 3- Menu de Loca��o \n\n 4- Sair");
		printf("\n\n>");
		scanf("%d",&opcao);
	}
}




