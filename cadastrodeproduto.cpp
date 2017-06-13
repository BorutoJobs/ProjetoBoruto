#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <locale.h>

struct produtos
{
	char nome[100],plataforma[50],genero[100],descricao[300];
    float preco;
	int codigo,qtd,ano,faixa;
}v[100];


int novo_produto()
{
    struct produtos;
    int sair=0,qtd_produtos=1,i;

	printf("\n <<Cadastro de Produto>> \n");


for(i=0;i<qtd_produtos;i++)
{
        printf("\n Codigo do produto(0-100): \n");
        fflush(stdin);
        scanf("%i",&v[i].codigo);
        printf("\n Nome do produto: \n");
        fflush(stdin);
        gets(v[i].nome);
        printf("\n Plataforma: \n");
        fflush(stdin);
        gets(v[i].plataforma);
        printf("\n Genero: \n");
        fflush(stdin);
        gets(v[i].genero);
        printf("\n Ano de Lançamento: \n");
        fflush(stdin);
        scanf("%i",&v[i].ano);
        printf("\n Faixa Etaria: \n");
        fflush(stdin);
        scanf("%i",&v[i].faixa);
        printf("\n Descrição: \n");
        fflush(stdin);
        gets(v[i].descricao);
        printf("\n Preço Unitario: \n");
        fflush(stdin);
        scanf("%f",&v[i].preco);
        printf("\n Quantidade: \n");
        fflush(stdin);
        scanf("%i",&v[i].qtd);
        printf("\n Cadastrar novo Produto?\n 1- Sim\n 2- Não \n");
        fflush(stdin);
        scanf("%i",&sair);
        if(sair==1)
        {
            qtd_produtos = qtd_produtos+1;
        }

}
return qtd_produtos;


}

int main()
{

int i,qtd_produtos;
struct produtos;

setlocale(LC_ALL,"portuguese");

qtd_produtos = novo_produto();
for(i=0;i<qtd_produtos;i++)
{
    printf("\n Codigo: %i Nome: %s Plataforma: %s Genero: %s \n Ano de Lançamento: %i Faixa Etarea: %i \n\n Descrição:\n %s \n Preço: %0.2f Quantidade: %i \n",v[i].codigo,v[i].nome,v[i].plataforma,v[i].genero,v[i].ano,v[i].faixa,v[i].descricao,v[i].preco,v[i].qtd);

}

system("pause");
}
