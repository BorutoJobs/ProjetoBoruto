#include "funcoes.h"
//AQUI DEVER�O SER DECLARADAS TODAS AS VARI�VEIS GLOBAIS E ESTRUTURAS QUE SER�O UTILIZADAS
int qtd_clientes = 0;

/*INICIO ESTRUTURAS REFERENTES AO CADASTRO DO CLIENTE*/
struct endereco{
	char rua[100], cep[20];	
};

struct jogos{
	char nome[50], plataforma[15], genero[20];
	//int qtDias;
	float preco; 
	int qtde;
};

struct jogos jg[33];

struct clientes{
	char nome[100];
	int idade;
	char cpf[15];
    struct endereco ender;
    struct jogos jg[10];
    int qt_jogos;
}v[100];

/*FIM ESTRUTURAS*/




//AQUI FICA O C�DIGO DE TODAS AS FUN��ES
//TODA E QUALQUER OUTRA FUN��O QUE FOR USADA DENTRO DE menuPrincipal DEVER� SER DECLARADA ANTES DELE!

//L� arquivo.txt e salva as informa��es na estrutura jogos
int leituraArquivo(){
	FILE *arq;
	char Linha[100];
	char *result;
	int i;
	int j;
	// Abre um arquivo TEXTO para LEITURA
	//Deve-se especificar o caminho exato do arquivo
	arq = fopen("jogos.txt", "r");
	if (arq == NULL){  // Se houve erro na abertura
	    printf("Problemas na abertura do arquivo\n");
    	return 0;
	}
  	i = 1;
  	j = 0;
  	while (!feof(arq)){
		// L� uma linha (inclusive com o '\n')
		result = fgets(Linha, 100, arq);  // o 'fgets' l� at� 99 caracteres ou at� o '\n'
		if (result){  // Se foi poss�vel ler
			//printf("Linha %d : %s",i,Linha);
			
			/*
			LINHA 1: NOME
			LINHA 2: G�NERO
			LINHA 3: PLATAFORMA
			LINHA 4: PRE�O
			*/
			jg[j].qtde = 5;
			if(i % 4 == 1){
				strcpy(jg[j].nome, Linha);
			}else if(i % 4 == 2){
				strcpy(jg[j].genero, Linha);
			}else if(i % 4 == 3){
				strcpy(jg[j].plataforma, Linha);
			}else if(i % 4 == 0){
				jg[j].preco = atof(Linha);

				j++;

			}			
			
		}
		i++;
	}
	fclose(arq);
}

//FUN��O QUE LISTA TODOS OS JOGOS NA struct jogos
void listaJogos(int opcao){
	int i;
	char p[20];
	if(opcao == 1){
		strcpy(p, "PS4\n");
	}else if(opcao == 2){
		strcpy(p, "XBOX ONE\n");
	}else{
		strcpy(p, "PC\n");
	}

	for(i = 0; i < 33; i++){
		if((jg[i].qtde > 0) && (strcmp(p, jg[i].plataforma) == 0)){
			printf("--Nome: %s", jg[i].nome);
			printf("--G�nero: %s", jg[i].genero);
			printf("--Plataforma: %s", jg[i].plataforma);
			printf("--Quantidade dispon�vel: %d\n", jg[i].qtde);
			printf("--Pre�o loca��o: R$%.2f", jg[i].preco);
			printf("\n\n###\n\n");
		}
	}
}

void listaJogosCod(int opcao){
	int i;
	char p[20];
	if(opcao == 1){
		strcpy(p, "PS4\n");
	}else if(opcao == 2){
		strcpy(p, "XBOX ONE\n");
	}else{
		strcpy(p, "PC\n");
	}

	for(i = 0; i < 33; i++){
		if((jg[i].qtde > 0) && (strcmp(p, jg[i].plataforma) == 0)){
			printf("--C�digo: %d\n", i+1);
			printf("--Nome: %s", jg[i].nome);
			printf("--G�nero: %s", jg[i].genero);
			printf("--Plataforma: %s", jg[i].plataforma);
			printf("--Pre�o loca��o: R$%.2f", jg[i].preco);
			printf("\n\n###\n\n");
		}
	}
}

int validarCPF(char cpf[]){
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os n�meros iguais ele � inv�lido.
    else{
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os n�meros de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 n�o for o mesmo que o da valida��o CPF � inv�lido
        else{	///digito 2--------------------------------------------------
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os n�meros de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 n�o for o mesmo que o da valida��o CPF � inv�lido
        }
    }
    return 1;
}	  

void cadastroCliente(){
    struct clientes;
    int sair = 0, i;
    char cpf[15];

	printf("\t\t <<Cadastro de Cliente>> \n");
	fflush(stdin);	
	do{
		i = qtd_clientes;
		printf("Informe o nome: ");
        gets(v[i].nome);
        fflush(stdin);
        printf("Informe a idade: ");
        scanf("%i", &v[i].idade);
        fflush(stdin);
        printf("Informe o CPF: ");
        gets(cpf);
        while(!validarCPF(cpf)){
        	fflush(stdin);
        	printf("\nCPF inv�lido! Informe novamente.");
        	printf("\nInforme o CPF: ");
        	gets(cpf);
		}
		strcpy(v[i].cpf, cpf);
        fflush(stdin);
        printf("Informe o endere�o (rua e n�mero): ");
        gets(v[i].ender.rua);
        fflush(stdin);
        printf("Informe o CEP: ");
        gets(v[i].ender.cep);
        v[i].qt_jogos = 0;
        fflush(stdin);
        system("cls");
        printf("Deseja cadastrar novo cliente?\n 1- Sim\n 2- N�o \n");
        fflush(stdin);
        scanf("%i", &sair);
        fflush(stdin);
		qtd_clientes++;
	}while(sair != 2);
}

void listaClientes(){
	int i, j;
	struct clientes;
	if(qtd_clientes > 0){
		for(i = 0; i < qtd_clientes; i++){
			printf("\n--Nome: %s", v[i].nome);
			printf("\n--CPF: %s", v[i].cpf);
			if(v[i].qt_jogos > 0){
				printf("\n\n--Jogos alugados: ");
				for(j = 0; j < v[i].qt_jogos; j++){
					printf("\n# %s", v[i].jg[j].nome);
					printf("# %s", v[i].jg[j].plataforma);
					printf("\n");
				}
			}else{
				printf("\nNenhum jogo alugado.");
			}
			printf("\n");
		}
		printf("\n\n");
	}else{
		printf("\nNenhum cliente cadastrado!\n\n");
	}
	system("pause");	
}

int busca_cliente(){
	struct clientes;
	char busca[100];
	int i,opcao,x,l,j;
	
	if(qtd_clientes==0)	{
		printf("\n N�o h� clientes cadastrados. ");
	}else{
		printf("\n Informe o CPF: ");
		fflush(stdin);
		gets(busca);
	
	    for(i=0;i<qtd_clientes;i++){	
			if(strcmp(busca,v[i].cpf)==0){
				printf("\n Nome: %s Idade: %i CPF: %s ",v[i].nome,v[i].idade,v[i].cpf);
				printf("\n Endere�o: \n--Rua: %s \n--CEP: %s ",v[i].ender.rua,v[i].ender.cep);
				if(v[i].qt_jogos > 0){
					printf("\n\n--Jogos alugados:");
					for(j = 0; j < v[i].qt_jogos; j++){
						printf("\n# %s", v[i].jg[j].nome);
						printf("# %s", v[i].jg[j].plataforma);
						printf("\n");
					}
				}else{
					printf("\nNenhum jogo alugado.");
				}
				
				printf("\n\nDeseja excluir o cadastro? 1- Sim 2- N�o\n");
				scanf("%i",&opcao);
				switch(opcao){
					case 1:
						if(i+1==qtd_clientes){
							qtd_clientes = qtd_clientes - 1;
						}else{
							for(x=i;x<qtd_clientes-1;x++){
								/*SUBSTITUIR TUDO ISSO POR v[i] = v[i+1] E VER SE FUNCIONA*/
								strcpy(v[i].nome , v[i+1].nome);
								v[i].idade = v[i+1].idade;
								strcpy(v[i].cpf , v[i+1].cpf);
								strcpy(v[i].ender.rua , v[i+1].ender.rua);
								strcpy(v[i].ender.cep , v[i+1].ender.cep);
								/**/
								if(v[i].qt_jogos > 0){
									for(l=0;l<10;l++){
										strcpy(v[i].jg[l].nome , v[i+1].jg[l].nome);
										strcpy(v[i].jg[l].plataforma , v[i+1].jg[l].plataforma);
										strcpy(v[i].jg[l].genero , v[i+1].jg[l].genero);
							    	}
								}else{
									printf("\nNenhum jogo alugado.");
								}
												
						    }
					    	qtd_clientes = qtd_clientes - 1;
						}
						break;
					
					case 2:
						printf("\nCadastro n�o exclu�do.");
						break;
						
					default:
						printf("\n Op��o invalida!");	
					break;
				}
	   		}
		}	
	}

}

void novaLocacao(int opcao){
	int cod;
	char cpf[15];
	int i, loc;
	int achou = 0;
	listaJogosCod(opcao);
	printf("\nInforme o c�digo do jogo desejado: ");
	scanf("%d", &cod);
	printf("\nJogo selecionado: %s", jg[cod - 1].nome);
	/*AQUI PEDIR CPF DO USU�RIO, VER SE � V�LIDO, BUSCAR NA ESTRUTURA SE H� CORRESPONDENTE PARA MOSTRAR INFORMA��ES (NOME) E PEDIR PARA CONFIRMAR LOCA��O*/
	/*FORMA DE PAGAMENTO?*/
	/*SALVAR JOGO NA STRUCT DO CLIENTE*/
	printf("\nInforme seu CPF: ");
	fflush(stdin);
	gets(cpf);
	while(!validarCPF(cpf)){
       	fflush(stdin);
       	printf("\nCPF inv�lido! Informe novamente.");
       	printf("\nInforme o CPF: ");
       	gets(cpf);
	}
	for(i = 0; i < qtd_clientes; i++){
		if(strcmp(cpf, v[i].cpf) == 0){
			achou = 1;
			printf("\nNome do cliente: %s", v[i].nome);
			printf("\n\n--Confirma loca��o? 1- Sim 2- N�o\n");
			fflush(stdin);
			scanf("%d", &loc);
			if(loc == 1){
				printf("\nLoca��o realizada com sucesso!");
				v[i].jg[v[i].qt_jogos] = jg[cod - 1];
				jg[cod - 1].qtde--;
				v[i].qt_jogos++;				
			}
		}		
	}
	if(!achou){
		printf("\nCliente n�o encontrado!");
	}
}

void menuPrincipal(){
	int opcao,sair=0;
	char nome [50];
	int op;

	while(sair!=256){   
		system("CLS"); 
		system("COLOR 0B");
		printf("><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><");
		printf("\t\t\t\t<<<<BEM VINDO A LOCACAO DE JOGOS BORUTO>>>> ");
		printf("\n<><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><><><><><>><");
		printf("\n\n\n\t\t\t\t\t\t1- LISTAR JOGOS DISPONIVEIS \n\t\t\t\t\t\t2- CLIENTES \n\t\t\t\t\t\t3- LOCA��O \n\t\t\t\t\t\t4- SAIR\n");
		scanf("%i",&opcao);
		system("CLS");

		switch(opcao){	
			case 1:	
				system("CLS");
				printf("\n\n <<<<LISTA DE JOGOS>>>> \n\n");
				printf("\nPlataformas dispon�veis: 1- PS4 2- XBOX ONE 3- PC.");
				printf("\nInforme sua op��o: ");
				scanf("%d", &op);      
				fflush(stdin);			
				system("CLS");
				printf("\n\n <<<<LISTA DE JOGOS>>>> \n\n");
				listaJogos(op);
				system("pause");
				//printf("\nAperte qualquer tecla para continuar");
				//getchar();
				fflush(stdin);
				break;

			case 2:
				printf("><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><");	
				printf("\t\t\t\t\t\t<<<<CLIENTES>>>> ");	
				printf("\n<><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><><><><><>><");
				printf("\n\n\n\t\t\t\t\t\t1- NOVO CLIENTE \n\t\t\t\t\t\t2- LISTAR CLIENTES \n\t\t\t\t\t\t3- BUSCAR CLIENTES \n\t\t\t\t\t\t4- VOLTAR\n");
				scanf("%i",&opcao);
		    	system("CLS");
				switch(opcao){
	    			case 1:
						printf("><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><");	
	        			printf("\t\t\t\t\t<<<<NOVO CLIENTE>>>> ");	
						printf("\n<><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><><><><><>><");
	          			fflush(stdin);
	          			cadastroCliente();
	    				system("PAUSE");
	    				system("CLS");		
			    		break;
			    
			    	case 2:
	    				printf("><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><");	
	        			printf("\t\t\t\t\t\t<<<<LISTAR CLIENTES>>>> ");	
						printf("\n<><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><><><><><>><");
						listaClientes();
	                  	system("CLS");
			    		break;
			    
			    	case 3:
	    				printf("><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><");	
	        			printf("\t\t\t\t\t<<<<BUSCAR CLIENTES>>>> ");	
						printf("\n<><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><><><><><>><");
						busca_cliente();
	          			fflush(stdin);
			  			getchar();
	              		system("PAUSE");
	              		system("CLS");
						/* Fun��o para buscar cliente aqui */
			    		break;
			    
			    	case 4:
	    				printf("Voltando...");	
	          			fflush(stdin);
			  			getchar();
			  			fflush(stdin);
	               		system("PAUSE");
	               		system("CLS");
						break;
	        	}
				break;
		
			case 3:
				printf("><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><");	
	        	printf("\t\t\t\t\t<<<<LOCA��O>>>> ");	
				printf("\n<><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><><><><><>><");
	    		printf("\n\n\n\t\t\t\t\t\t1- NOVA LOCA��O\n\t\t\t\t\t\t2-VOLTAR\n");
				scanf("%i",&opcao);
				system("CLS");
			    switch(opcao){
	    			case 1:
	    				printf("><><><><><><><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><");	
	        			printf("\t\t\t\t\t<<<<NOVA LOCA��O>>>> ");	
						printf("\n<><><><><><><><><><><><><><><><><><<><><><><><><><><><><><<><>><><><><><><><><><><><><><><><><>><><><><><><><><><><><>><");
						printf("\nPlataformas dispon�veis: 1- PS4 2- XBOX ONE 3- PC.");
						printf("\nInforme sua op��o: ");
						scanf("%d", &op);
						novaLocacao(op);
	          			fflush(stdin);
			  			getchar();
	              		system("PAUSE");
	              		system("CLS");
	    				/* Fun��o para realizar a loca�ao aqui */   
						break;
	       			 case 2:
			        	printf("Voltando...");	
	          			fflush(stdin);
			  			getchar();
	               		//system("PAUSE");
	               		system("CLS");
						break;
				}
				break;
			case 4:
				sair = 256;
				printf("\n\nSaindo...");
				break;
			default:
				printf("Op��o inv�lida!");	
	          	fflush(stdin);
			  	getchar();
	            system("PAUSE");
	            system("CLS");
				break;	  
		}	
	}
	//system("pause");
}







