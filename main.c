#include<stdio.h>
#include<stdlib.h>
#include"prototipos.h"

struct elemento{
	struct cadastro dados;
	struct elemento *prox;
};
typedef struct elemento *Elem;

int main(){

	Pilha *pi;
	int op;
	
	pi = cria_pilha();
	
	do{
		printf("1 - empilhar:\n");
		printf("2 - desempilhar:\n");
		printf("3 - tamanho da pilha\n");
		printf("4 - liberar pilha\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				if((pilha_cheia(pi))==1){
					printf("Pilha cheia!\n");
				}else{
					struct cadastro alunos;
					printf("Digite sua matricula:\n");
					scanf("%d", &alunos.cod);
					printf("Digite seu nome:\n");
					scanf(" %[^\n]", alunos.nome);
					printf("Digite sua primeira nota:\n");
					scanf("%f", &alunos.nota1);
					printf("Digite sua segunda nota:\n");
					scanf("%f", &alunos.nota2);
					insere_pilha(pi, alunos);	
				}
			break;
			case 2:
				if((pilha_vazia(pi))==1){
					printf("Pilha vazia!\n");
				}else{
					int remocao = remove_pilha(pi);
					if(remocao){
						printf("Pilha removida com sucesso!\n");
					}else{
						printf("Erro na remocao!\n");
					}
				}
			break;
			case 3:
				if((pilha_vazia(pi))==1){
					printf("pilha vazia!\n");
				}else{
					int tamanho = tamanho_pilha(pi);
					printf("tamanho da pilha: %d\n", tamanho);
				}
			break;
			case 4:
				if((pilha_vazia(pi))==1){
					printf("pilha vazia!\n");
				}else{
					libera_pilha(pi);
					if((pilha_vazia(pi))==1){
						printf("pilha esvaziada!\n");
					}
				}
			break;
		}
	}while(op<=4);
	

	return 0;
}

Pilha* cria_pilha(){
	Pilha *pi;
	pi = (Pilha* ) malloc(sizeof(Pilha));
	if(pi == NULL){
		*pi == NULL;
	}
	return pi;
}

int pilha_cheia(Pilha *pi){
	return 0;
}

int pilha_vazia(Pilha *pi){
	if(pi == NULL){
		return 1;
	}
	if(*pi == NULL){
		return 1;
	}
	return 0;
}

//empilhar
int insere_pilha(Pilha *pi, struct cadastro alunos){
	if(pi == NULL){
		return 0;
	}
	Elem* no;
	no = (Elem *) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	no->dados = alunos;
	no->prox = (*pi);
	*pi = no;
	return 1; 
}

//desempilhar
int remove_pilha(Pilha *pi){
	if(pi == NULL){
		return 0;
	}
	if((*pi) == NULL){
		return 0;
	}
	Elem *no = *pi;
	*pi = no->prox;
	free(no);
	return 1;
}

//tamanho da pilha
int tamanho_pilha(Pilha *pi){
	if(pi == NULL){
		return 0;
	}
	int cont = 0;
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	return 0;
}

//liberar pilha
int libera_pilha(Pilha *pi){
	if(pi != NULL){
		Elem *no;
		while((*pi) != NULL){
			no = *pi;
			*pi = *pi->prox;
			free(no)
		}
		free(pi);
	}
}
