#include <stdio.h>

struct cadastro{
  int mat;
  char nome;
};
typedef struct elemento Pilha;

struct elemento{
  struct cadastro dados;
  struct elemento *prox;
};
typedef struct elemento *Elem;

int main(){

  Pilha *pi;
  pi = cria_pilha();
  
  return 0;
}

Pilha* cria_pilha{
  Pilha *pi;
  pi = (Pilha *) malloc(sizeof(Pilha));
  if(pi == NULL){
    *pi == NULL;
  }
  return pi;
}

int libera_pilha(Pilha *pi){
  if(pi != NULL){
    Elem *no;
      while((*pi) != NULL){
        no = *pi;
        *pi = (*pi)->prox;
        free(no);
    }
  free(pi);
  }
  return 1;
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

int tamanho_pilha(Pilha *pi){
  if(pi == NULL){
    return 0;
  }
  int cont = 0;
  Elem *no = *pi;
  while(no != NULL){
    cont++;
    no = no->prox;
  }
  return cont;
}

int insere_pilha(Pilha *pi, struct cadastro aluno){
  if(pi == NULL){
    return 0;
  }
  Elem *no;
  no = (Pilha *) malloc(sizeof(Pilha));
  if(no == NULL){
    return 0;
  }
  no->dados = aluno;
  no->prox = *pi;
  *pi = no;
  return 1;
}
