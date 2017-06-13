#include <iostream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <locale.h>


int main() 
{
	int opcao=0,sair=0;

setlocale(LC_ALL,"Portuguese");

while(sair!=256)
{
	printf("\n\n <<<<BEM VINDO A LOCACAO DE JOGOS BORUTO>>>> \n\n");
	printf(" 1- Produtos \n\n 2- Clientes \n\n 3- Locação \n\n 4- Sair");
	scanf("%i",&opcao);
	
	switch(opcao)
	{
		case 1:
		printf("\n\n <<<<Produtos>>>> \n\n");	
		printf(" 1- Novo Produto \n\n 2- Excluir Produto \n\n 3- Buscar Produto \n\n 4- Sair");
		scanf("%i",&opcao);
		    switch(opcao)
	    	{
	    		case 1:
	    		/* Função para cadastrar produto aqui */
			    break;
			    
			    case 2:
	    		/* Função para excluir produto aqui */
			    break;
			    
			    case 3:
	    		/* Função para buscar produto aqui */
			    break;
			    
			    case 4:
			    break;
	        }
		break;
		
		case 2:
		printf("\n\n <<<<Clientes>>>> \n\n");	
		printf(" 1- Novo Cliente \n\n 2- Excluir Cliente \n\n 3- Buscar Cliente \n\n 4- Sair");
		scanf("%i",&opcao);
		    switch(opcao)
	    	{
	    		case 1:
	    		/* Função para cadastrar cliente aqui */
			    break;
			    
			    case 2:
	    		/* Função para excluir cliente aqui */
			    break;
			    
			    case 3:
	    		/* Função para buscar cliente aqui */
			    break;
			    
			    case 4:
			    break;
	        }
		break;
		
		case 3:
		printf("\n\n <<<<Locação>>>> \n\n");	
		printf(" 1- Nova Locação \n\n 2- Verificar Locações \n\n 3- Sair");
		scanf("%i",&opcao);
		    switch(opcao)
	    	{
	    		case 1:
	    		/* Função para realizar a locaçao aqui */
			    break;
			    
			    case 2:
	    		/* Função para verificar as locaçoes já feitas  aqui */
			    break;
			    
			    case 3:
			    break;
	        }
		break;
		
		case 4:
		sair = 256;
		break;
	}
}
	system("pause");
}
