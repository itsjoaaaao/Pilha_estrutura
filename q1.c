#include<stdio.h>
#include<stdlib.h>
#include"q1dados.h"
#include<string.h>

struct elemento{
	struct palavra dados;
	struct elemento *prox;
}; 
typedef struct elemento Elem;

int main(){

	Pilha *pi, *p2;
	int op;

	pi = cria_pilha();
	p2 = cria_pilha();
	
	do{
		printf("1-inserir:\n");
		printf("2-desempilhar:\n");
		printf("3-mostrar:\n");
		printf("4-consultar:\n");
		printf("5-liberar:\n");
		printf("6-tamanho:\n");
		printf("7-empilhar na outra pilha:\n");
		printf("8-mostrar outra pilha:\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				if(pilha_cheia(pi)==1){
					printf("pilha cheia!\n");
				}else{
					struct palavra pal;
					printf("Digite seu nome:\n");
					scanf("%s", pal.letra);
					printf("Digite sua idade:\n");
					scanf("%d", &pal.id);
					insere(pi, pal);
				}
			break;
			case 2:
				if(pilha_vazia(pi)==1){
					printf("pilha vazia!\n");
				}else{
					int rem = desempilhar(pi);
					if(rem){
						printf("pilha desempilhada\n");
					}
				}
			break;
			case 3:
				if(pilha_vazia(pi)==1){
					printf("pilha vazia!\n");
				}else{
					imprimir(pi);
				}
			break;
			case 4:
				if(pilha_vazia(pi)==1){
					printf("pilha vazia!\n");
				}else{
					struct palavra pal;
					int consul = consulta(pi, &pal);
					if(consul){
						printf("Dados:\n");
						printf("Nome: %s", pal.letra);
						printf("Idade: %d", pal.id);
					}	
				}
			break;
			case 5:
				if(pilha_vazia(pi)==1){
					printf("pilha vazia!\n");
				}else{
					libera(pi);
					if(pilha_vazia==1){
						printf("pilha esvaziada!\n");
					}
				}
			break;
			case 6:
				if(pilha_vazia(pi)==1){
					printf("pilha vazia!\n");
				}else{
					int tamanho = tamanho(pi);
					printf("tamanho da pilha: %d\n", tam);
				}
			break;
			case 7:
				if(pilha_vazia(pi)==1){
					printf("pilha vazia!\n");
				}else{
					struct palavra pal;
					insere(p2, pal);
				}
			break;
			case 8:
				if(pilha_vazia(pi)==1){
					printf("pilha vazia!\n");
				}else{
					imprimir(p2);
				}
      			break;	
		}
		
		
	}while(op<=8);
	

	return 0;
}

Pilha* cria_pilha(){
	Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
	if(pi != NULL){
		*pi == NULL;
	}
	return pi;
}

int pilha_cheia(Pilha* pi){
	return 0;
}

int pilha_vazia(Pilha* pi){
	if(pi == NULL){
		return 1;
	}
	if(*pi == NULL){
		return 1;
	}
	return 0;
}

int insere(Pilha* pi, struct palavra pal){
	if(pi == NULL){
		return 0;
	}
	Elem* no;
	no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	no->dados = pal;
	no->prox = (*pi);
	*pi = no;
	return 1;
}

int desempilhar(Pilha* pi){
	if(pi == NULL){
		return 0;
	}
	if((*pi)==NULL){
		return 0;
	}
	Elem *no = *pi;
	*pi = no->prox;
	*pi = no;
	return 1;
}

void imprimir(Pilha* pi){
	if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("nome: %s\n", no->dados.letra);
        printf("idade: %d\n", no->dados.id);
        no = no->prox;
    }
}

int consulta(Pilha* pi, struct palavra *pal){
	if(pi==NULL)
		return 0;
	if((*pi)==NULL)
		return 0;
	*pal = (*pi)->dados;
	return 1;
}

void libera(Pilha* pi){
	if(pi != NULL){
		Elem* no;
		while((*pi) != NULL){
			no = *pi;
			*pi = pi->prox;
			free(no);
		}
		free(pi);
	}
}

int tamanho(Pilha* pi){
	if(pi == NULL){
		return 0;
	}
	int cont = 0;
	Elem* no = *pi;
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	return cont;
}
