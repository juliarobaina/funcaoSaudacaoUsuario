#include <stdio.h>
#include <stdlib.h>

//corpo das funções
void cleanString(char* nomeUsuario, char* novoNomeUsuario,int tam);
int countStr(char* nomeUsuario);
void tudoMinusculoMenosPrimeiraLetra(char* str,int tam);
void imprimirNome(char* nomeUsuario);


int main(){
	
	//Criar ponteiro de char
	char *nomeUsuario; 

	//Alocar memória 
	nomeUsuario = (char*) malloc(101 * sizeof(char));
	
	//Imprimir na tela a mensagem para o usuário
	printf("Digite seu nome: ");

	//Receber o que o usuário digitou
	fgets(nomeUsuario,101,stdin);
	
	//Mandar imprimir a mensagem de olá para o usuário
	imprimirNome(nomeUsuario);
	
	
	//Liberar a memória de nomeUsuario
	free(nomeUsuario);


	return 0;
}



//Remover caracteres indesejados
void cleanString(char* nomeUsuario, char* novoNomeUsuario,int tam){
	
	int count = 0;

	for(int i = 0; i < tam;i++){	

		//Se nomeUsuario[i] for letra do alfabeto ou nomeUsuario[i] for espaço (com algumas restrições), faça
		if(((nomeUsuario[i] >= 'A' && nomeUsuario[i] <= 'Z') 
			|| (nomeUsuario[i] >= 'a' && nomeUsuario[i] <= 'z')) 
			|| (nomeUsuario[i] == 32 && i > 0 && ((nomeUsuario[i-1] >= 'A' 
				&& nomeUsuario[i-1] <= 'Z') || (nomeUsuario[i-1] >= 'a' 
				&& nomeUsuario[i-1] <= 'z')))){
			
			//valor de novoNomeUsuario recebe valor de nomeUsuario
			*novoNomeUsuario = nomeUsuario[i];
			//aponta para a próxima posição da memória de novoNomeUsuario
			novoNomeUsuario++;
			//incremento count para acompanhar o preenchimento de novoNomeUsuario
			count++;
		}
	}

	//Verificar se o último caracter da string é espaço e substituir o valor por final de linha. *(novoNomeUsuario - 1), para não considerar o caracter de final de linha
	if(*(novoNomeUsuario - 1) == 32)
		*(novoNomeUsuario - 1) = '\0';


	//Aponta para o início do ponteiro
	novoNomeUsuario = (novoNomeUsuario - count);
	
}

//Contar quantidade de caracteres da string
int countStr(char* nomeUsuario){
	
	int count = 0;
	
	//obter o total de caracteres
	for(count; nomeUsuario[count] != '\0';count++);
	
	//remover a contagem extra
	count--;
	
	return count;
}

//Converter as letras para minúsculo, menos a primeira
void tudoMinusculoMenosPrimeiraLetra(char* str,int tam){

	if((str[0] >= 'a' && str[0] <= 'z'))//Converter a primeira letra em maiúsculo
		str[0] = 'A' + (str[0] - 'a'); //De acordo com a tabela ASCII

	//Converter as demais letras para minúsculo
	for(int i = 1; i < tam;i++){
		
		if((str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = (str[i] - 'A') + 'a'; //De acordo com a tabela ASCII
	}
}

//imprimir mensagem de olá para o usuário
void imprimirNome(char* nomeUsuario){

	char* novoNomeUsuario;
	novoNomeUsuario = (char*) malloc(101 * sizeof(char));

	//Receber total de caracteres da string
	int count = countStr(nomeUsuario);

	//Remover caracteres indesejados
	cleanString(nomeUsuario,novoNomeUsuario,count);

	/*
	Receber total de caracteres da string novoNomeUsuario + 1, pois 
	foi retirado novamente mais um loop em excesso, da remoção anterior em count, e isso altera o tamanho 
	real da string, isso explica a adição de uma unidade.*/
	count = countStr(novoNomeUsuario);

	//A string não está vazia
	if(count != -1){

		count++;
		
		tudoMinusculoMenosPrimeiraLetra(novoNomeUsuario,count);

		//imprimir a saudação
		printf("\nOlá, %s!\n\n",novoNomeUsuario);

		
	}else //String vazia
		printf("\nOlá, Mundo!\n\n");


	free(novoNomeUsuario);
}
