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
system("COLOR 0B");
	printf("><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><");
	printf("\t\t\t\t<<<<BEM VINDO A LOCACAO DE JOGOS BORUTO>>>> ");
	printf("\n<><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><><><><><>><");
	printf("\n\n\n\t\t\t\t\t\t1- PRODUTOS \n\t\t\t\t\t\t2- CLIENTES \n\t\t\t\t\t\t3- LOCA��O \n\t\t\t\t\t\t4- SAIR: ");
	scanf("%i",&opcao);
	system("CLS");

	switch(opcao)
	{
	
		case 1:
	
		printf("\n\n <<<<Produtos>>>> \n\n");	
		printf(" 1- NOVO PRODUTO \n\n 2- EXCLUIR PRODUTO \n\n 3- BUSCAR PRODUTO \n\n 4- SAIR: ");
		scanf("%i",&opcao);
	system("CLS");

		    switch(opcao)
	    	{
	    		case 1:
	    		/* Fun��o para cadastrar produto aqui */
			    break;
			    
			    case 2:
	    		/* Fun��o para excluir produto aqui */
			    break;
			    
			    case 3:
	    		/* Fun��o para buscar produto aqui */
			    break;
			    
			    case 4:
			    break;
	        }
		break;
		
		case 2:
		printf("\n\n <<<<Clientes>>>> \n\n");	
		printf(" 1- NOVO CLIENTE \n\n 2- EXCLUIR CLIENTE \n\n 3- BUSCAR CLIENTE \n\n 4- SAIR: ");
		scanf("%i",&opcao);
		    	system("CLS");

			switch(opcao)
	    	{
	    		case 1:
	    		/* Fun��o para cadastrar cliente aqui */
			    break;
			    
			    case 2:
	    		/* Fun��o para excluir cliente aqui */
			    break;
			    
			    case 3:
	    		/* Fun��o para buscar cliente aqui */
			    break;
			    
			    case 4:
			    break;
	        }
		break;
		
		case 3:
		printf("\n\n <<<<Loca��o>>>> \n\n");	
		printf(" 1- NOVA LOCA��O \n\n 2- VERIFICAR LOCA��ES \n\n 3- SAIR: ");
		scanf("%i",&opcao);
	system("CLS");

		    switch(opcao)
	    	{
	    		case 1:
	    		/* Fun��o para realizar a loca�ao aqui */
			    break;
			    
			    case 2:
	    		/* Fun��o para verificar as loca�oes j� feitas  aqui */
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
