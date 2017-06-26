#include <windows.h>

char centralizar(char *texto) //função pra centralizar
{
	int n,r,i;
	
	int x = GetSystemMetrics(SM_CXSCREEN);
	
	
	n = strlen(texto);
	r = ((x/8)-n)/2;
	
	for(i=0;i<r;i++)
	{
		printf(" ");
	}
	for(i=0;i<n;i++)
	{
		printf("%c",texto[i]);
	}
}


int main()  // chamada de teste da função
{
	char texto[100];
	
	strcpy(texto,"<<Locadora de Jogos Borutoooooooooooooooooooooooooooooo>>");
	printf("\n\n\n");
	centralizar(texto);
}
