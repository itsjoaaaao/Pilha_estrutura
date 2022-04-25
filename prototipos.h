#include<stdio.h>
#include<stdlib.h>

struct cadastro{
	int cod;
	char nome[20];
	float nota1, nota2;
};
typedef struct elemento* Pilha;

Pilha* cria_pilha(); 
int pilha_cheia();
int pilha_vazia();
int insere_pilha(Pilha *pi, struct cadastro alunos);
int remove_pilha(Pilha *pi);
int tamanho_pilha(Pilha *pi);
