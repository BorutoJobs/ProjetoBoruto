#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <locale.h>

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


int novo_cliente(){
    struct clientes;
    int sair = 0, qtd_clientes = 1, i;

	printf("\t\t <<Cadastro de Cliente>> \n");


for(i = 0; i < qtd_clientes; i++){
	
       /* printf("Informe o nome: ");
        fflush(stdin);
        gets(v[i].nome);
        printf("Informe a idade: ");
        scanf("%i", &v[i].idade);
        printf("Informe o CPF: ");
        scanf("%i", &v[i].cpf);
        printf("Informe o endereço: ");
        fflush(stdin);
        gets(v[i].endereco); */
        printf("Informe o endereço: \nRua, numero: ");
        gets(v[i].ender.rua);
        fflush(stdin);
        printf("Informe o CEP: ");
        gets(v[i].ender.cep);
        system("cls");
        printf("Deseja cadastrar novo cliente?\n 1- Sim\n 2- Não \n");
        fflush(stdin);
        scanf("%i", &sair);
        system("cls");
		    if(sair==1){
            qtd_clientes = qtd_clientes + 1;
            }
}
return qtd_clientes;

}


int main(){

int i, qtd_clientes;
struct clientes;

setlocale(LC_ALL,"");

qtd_clientes = novo_cliente();
for(i = 0; i < qtd_clientes; i++){
   //SE PRECISAR FAZER NOVAMENTE -> printf("Nome: %s \nIdade: %i \nSexo: %s \nCPF: %i \nEndereço: %s \n\n", v[i].nome, v[i].idade, v[i].cpf, v[i].endereco);
   printf("Rua: %s \nCEP: %s \n", v[i].ender.rua, v[i].ender.cep);
}


system("pause");
}

