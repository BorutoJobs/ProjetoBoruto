#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

//AQUI FICA SOMENTE O MAIN

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"");
	
	leituraArquivo();
	menuPrincipal();
	return 0;
}
