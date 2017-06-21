#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>


struct jogos{
	char nome[50], plataforma[15];
	int qtDias;
	float preco; 
};

struct endereco{
	char rua[100], cep[20];
	
}endereco;


struct clientes{
	char nome[100];
	int idade, cpf;
    struct endereco ender;
    struct jogos jg[10];
}v[100];


int novo_cliente(int qtd_clientes){
    struct clientes;
    int sair = 0, i;

	printf("\t\t <<Cadastro de Cliente>> \n");


for(i = qtd_clientes; i < qtd_clientes+1; i++){
	
        printf("Informe o endereço: \nRua, numero: ");
        fflush(stdin);
        gets(v[i].ender.rua);
        printf("Informe o CEP: ");
        fflush(stdin);
        gets(v[i].ender.cep);
        system("cls");
        qtd_clientes = qtd_clientes + 1;
        printf("Deseja cadastrar novo cliente?\n 1- Sim\n 2- Não \n");
        fflush(stdin);
        scanf("%i", &sair);
        system("cls");
		    if(sair==2){
            break;
            }
}
return qtd_clientes;

}

int busca_clientes(int localizado, int qtd_clientes)
{
	struct clientes;
	char busca[100];
	int i;
	
	printf("\n Busca: ");
	fflush(stdin);
	gets(busca);
	
	strlwr(busca);

for(i=0;i<qtd_clientes;i++)	
{
	strlwr(v[i].nome);
	strlwr(v[i].ender.rua);
	strlwr(v[i].ender.cep);
// cpf inteiro	strlwr(v[i].cpf);
	
	
	if((strcmp(busca,v[i].nome)==0) || (strcmp(busca,v[i].ender.rua)==0) || (strcmp(busca,v[i].ender.cep)==0))
{
	printf("\n Nome: %s Idade: %i CPF: %i ",v[i].nome,v[i].idade,v[i].cpf);
	printf("\n Endereço: \n Rua: %s CEP: %s ",v[i].ender.rua,v[i].ender.cep);
	localizado = 1;
}
}

return localizado;
}






int main(int argc, char** argv)
{
	int opcao=0,qtd_clientes=0,localizado,i;

while(opcao!=3)
{
	printf("\n 1- Teste cadastrar  \n 2- Teste buscar \n\n");
	scanf("%i",&opcao);
	
	switch(opcao)
	{
		case 1:
			qtd_clientes =  novo_cliente(qtd_clientes);
			for(i = 0; i < qtd_clientes; i++)
			{
             printf("Rua: %s \nCEP: %s \n", v[i].ender.rua, v[i].ender.cep);
            }
			break;
			
		case 2:
			localizado = busca_clientes(localizado,qtd_clientes);
			break;
			
	}
}
	
}
