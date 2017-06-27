#include "funcoes.h"
#include <windows.h>

int qtd_clientes = 0;	//VAR�AVEL QUE CONTROLA O N�MERO TOTAL DE CLIENTES CADASTRADOS E V�LIDOS

/*INICIO ESTRUTURAS*/
struct endereco{
	char rua[100], cep[20];	
};

struct jogos{
	char nome[50], plataforma[15], genero[20];
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

//FUN��O PARA CENTRALIZAR O TEXTO
char centralizar(char *texto) 
{
	int n,r,i;
	
	int x = GetSystemMetrics(SM_CXSCREEN);
	
	
	n = strlen(texto);
	r = ((x/8.16)/2)-(n/2);
	for(i=0;i<r;i++)
	{
		printf(" ");
	}

}

//L� ARQUIVO DE TEXTO E SALVA AS INFORMA��ES NA ESTRUTURA DE JOGOS. FONTE: material complementar
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
			e assim por diante
			*/
			jg[j].qtde = 5;			//Todos os jogos iniciam com a quantidade 5;
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

//FUN��O QUE LISTA TODOS OS JOGOS DA ESTRUTURA DE JOGOS
void listaJogos(int opcao){
	int i;
	char p[20];
	//Recebe a op��o informada para filtragem
	if(opcao == 1){
		strcpy(p, "PS4\n");
	}else if(opcao == 2){
		strcpy(p, "XBOX ONE\n");
	}else{
		strcpy(p, "PC\n");
	}
	//La�o percorre toda o vetor e s� imprime os da plataforma escolhida
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

//FUN��O QUE LISTA TODOS OS JOGOS NA struct jogos, COM ADI��O DE C�DIGO USADO NA LOCA��O
void listaJogosCod(int opcao){
	int i;
	char p[20];
	//Recebe a op��o informada para filtragem
	if(opcao == 1){
		strcpy(p, "PS4\n");
	}else if(opcao == 2){
		strcpy(p, "XBOX ONE\n");
	}else{
		strcpy(p, "PC\n");
	}
	//La�o percorre toda o vetor e s� imprime os da plataforma escolhida
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

//FUN��O PARA VALIDAR CPF. FONTE: http://wurthmann.blogspot.com.br/2012/12/funcao-em-linguagem-c-validador-de-cpf.html
int validarCPF(char cpf[]){
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; //se o CPF tiver todos os n�meros iguais ele � inv�lido.
    else{
        //digito 1----------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os n�meros de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; //se o digito 1 n�o for o mesmo que o da valida��o CPF � inv�lido
        else{	//digito 2---------------------
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) //multiplica os n�meros de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; //se o digito 2 n�o for o mesmo que o da valida��o CPF � inv�lido
        }
    }
    return 1;
}	  

//FUN��O PARA CADASTRO DE NOVO CLIENTE
void cadastroCliente(){
    struct clientes;
    int sair = 0, i;
    int j;
    char cpf[15];
    int existente = 0;

	printf("\t\t <<Cadastro de Cliente>> \n");
	fflush(stdin);
	//Executa enquanto 'sair' for diferente de 2	
	do{
		i = qtd_clientes;
		printf("Informe o nome: ");
        gets(v[i].nome);
        fflush(stdin);
        printf("Informe a idade: ");
        scanf("%i", &v[i].idade);
        //La�o que verifica o CPF
        do{
        	fflush(stdin);
	        printf("Informe o CPF: ");
	        gets(cpf);
			//Enquanto CPF for inv�lido, informa-se novamente
        	while(!validarCPF(cpf)){
	        	fflush(stdin);
	        	printf("\nCPF inv�lido! Informe novamente.");
	        	printf("\nInforme o CPF: ");
	        	gets(cpf);
			}
			//Compara-se o CPF informado com os CPFs j� cadastrados. Se j� existir, informa-se novamente
			for(j = 0; j < i; j++){
				if(strcmp(cpf, v[j].cpf) == 0){
					printf("\nCPF j� cadastrado! Informe novamente.\n");
					existente = 1;				
				}else{
					existente = 0;
				}
			}       	
		}while(existente);	//Sai do la�o quando CPF for v�lido e n�o repetido     
		
		strcpy(v[i].cpf, cpf);
        fflush(stdin);
        printf("Informe o endere�o (rua e n�mero): ");
        gets(v[i].ender.rua);
        fflush(stdin);
        printf("Informe o CEP: ");
        gets(v[i].ender.cep);
        v[i].qt_jogos = 0;	//Quantidade de jogos alugador � inicializado com 0
        fflush(stdin);
        system("cls");
        printf("Deseja cadastrar novo cliente?\n 1- Sim\n 2- N�o \n");
        fflush(stdin);
        scanf("%i", &sair);
        fflush(stdin);
		qtd_clientes++;	//N�mero total de clientes � atualizado
	}while(sair != 2);
}

//FUN��O QUE LISTA TODOS OS CLIENTES EXISTENTES
void listaClientes(){
	int i, j;
	struct clientes;
	//Se n�o houver clientes cadastrados, imprime a mensagem
	if(qtd_clientes > 0){
		//La�o percorre o vetor que armazena os clientes e imprime suas informa��es
		for(i = 0; i < qtd_clientes; i++){
			printf("\n--Nome: %s", v[i].nome);
			printf("\n--CPF: %s", v[i].cpf);
			//Se nenhum jogo foi alugado, imprime a mensagem
			if(v[i].qt_jogos > 0){
				printf("\n\n--Jogos alugados: ");
				//La�o percorre o vetor que armazena os jogos e imprime suas informa��es
				for(j = 0; j < v[i].qt_jogos; j++){
					printf("\n#Jogo: %s", v[i].jg[j].nome);
					printf("#Plataforma: %s", v[i].jg[j].plataforma);
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


//FUN��O QUE BUSCA UM CLIENTE
int busca_cliente(){
	struct clientes;
	char busca[100];
	int i,opcao,x,l,j;
	
	if(qtd_clientes==0)	{
		printf("\n N�o h� clientes cadastrados. ");
	}else{
		//A busca � realizada pelo CPF
		printf("\n Informe o CPF: ");
		fflush(stdin);
		gets(busca);
		//La�o percorre o vetor que armazena os clientes e procura pelo CPF
	    for(i=0;i<qtd_clientes;i++){	
			if(strcmp(busca,v[i].cpf)==0){
				printf("\n Nome: %s Idade: %i CPF: %s ",v[i].nome,v[i].idade,v[i].cpf);
				printf("\n Endere�o: \n--Rua: %s \n--CEP: %s ",v[i].ender.rua,v[i].ender.cep);
				if(v[i].qt_jogos > 0){
					printf("\n\n--Jogos alugados:");
					for(j = 0; j < v[i].qt_jogos; j++){
						printf("\n#Jogo: %s", v[i].jg[j].nome);
						printf("#Plataforma: %s", v[i].jg[j].plataforma);
						printf("\n");
					}
				}else{
					printf("\nNenhum jogo alugado.");
				}
				//Se cliente � encontrado, pode-se realizar a exclus�o
				printf("\n\nDeseja excluir o cadastro? 1- Sim 2- N�o\n");
				scanf("%i",&opcao);
				switch(opcao){
					case 1:
						//Se o cliente for o primeiro ou o �ltimo, a quantidade total de clientes � decrementada, apagando as informa��es do mesmo
						if(i+1==qtd_clientes){
							qtd_clientes = qtd_clientes - 1;
						}else{
							//La�o come�a na posi��o do vetor que cont�m o cliente e vai at� o pen�ltimo elemento;
							//A cada itera��o, copia-se o conte�do do cliente seguinte (i+1) para o anterior (i);
							for(x=i;x<qtd_clientes-1;x++){
								v[i] = v[i+1];		//Como cada posi��o do vetor guarda uma estrutura do mesmo tipo, pode-se fazer essa atribui��o direta
								//Copia-se as informa��es referentes aos jogos alugados pelo cliente
								if(v[i].qt_jogos > 0){
									for(l=0;l<10;l++){
										v[i].jg[l] = v[i+1].jg[l];
							    	}
								}
												
						    }
					    	qtd_clientes = qtd_clientes - 1;	//Quantidade total de clientes � decrementada
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

//FUN��O QUE CONTROLA NOVAS LOCA��ES
void novaLocacao(int opcao){
	int cod;
	char cpf[15];
	int i, loc;
	int achou = 0;
	//Lista todos os jogos
	listaJogosCod(opcao);
	printf("\nInforme o c�digo do jogo desejado: ");
	scanf("%d", &cod);
	printf("\nJogo selecionado: %s", jg[cod - 1].nome);
	//Deve-se informar um CPF v�lido e j� cadastrado para a realiza��o da loca��o
	printf("\nInforme seu CPF: ");
	fflush(stdin);
	gets(cpf);
	while(!validarCPF(cpf)){
       	fflush(stdin);
       	printf("\nCPF inv�lido! Informe novamente.");
       	printf("\nInforme o CPF: ");
       	gets(cpf);
	}
	//La�o percorre o vetor que cont�m todos os clientes e busca pelo CPF;
	//Se n�o foi encontrado um cliente, imprime a mensagem
	for(i = 0; i < qtd_clientes; i++){
		if(strcmp(cpf, v[i].cpf) == 0){
			achou = 1;
			printf("\nNome do cliente: %s", v[i].nome);
			printf("\n\n--Confirma loca��o? 1- Sim 2- N�o\n");
			fflush(stdin);
			scanf("%d", &loc);
			if(loc == 1){
				printf("\nLoca��o realizada com sucesso!");
				//Se a loca��o for confirmada, as informa��es do jogo s�o copiadas para o cliente;
				v[i].jg[v[i].qt_jogos] = jg[cod - 1];
				jg[cod - 1].qtde--;					//O n�mero de jogos dispon�vel � decrementado
				v[i].qt_jogos++;					//O n�mero de jogos alugados � incrementado
			}
		}		
	}
	if(!achou){
		printf("\nCliente n�o encontrado!");
	}
}

void menuPrincipal(){
	int opcao,sair=0;
	char nome [50],texto[]="BEM VINDO A LOCACAO DE JOGOS BORUTO";
	int op;

	while(sair!=256){   
		system("CLS"); 
		system("COLOR 0B");
	
    	printf("\n\n");
	    centralizar(texto);
	    printf("%s",texto);
	    printf("\n\n");
	    centralizar(texto);
		printf("1- LISTAR JOGOS DISPONIVEIS");
		printf("\n");
		centralizar(texto);
		printf("2- CLIENTES");
		printf("\n");
		centralizar(texto);
		printf("3- LOCA��O");
		printf("\n");
		centralizar(texto);
		printf("4- SAIR");
		printf("\n");
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







