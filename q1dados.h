#include<stdio.h>
#include<stdlib.h>

struct palavra{
	int id;
	char letra[30];	
};
typedef struct elemento* Pilha;

Pilha* cria_pilha();
int pilha_cheia(Pilha* pi);
int pilha_vazia(Pilha* pi);
int insere(Pilha* pi, struct palavra pal);
int desempilhar(Pilha* pi);
void imprimir(Pilha* pi);
int consulta(Pilha* pi, struct palavra *pal);
void libera(Pilha* pi);
int tamanho(Pilha* pi);
