#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int numero;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct {
    No* raiz;
} Arvore;

 
void criaArvore(Arvore* arvore) {
    arvore->raiz = NULL;
}

int isVazia(Arvore arvore) {
    return arvore.raiz == NULL;
}

int isNulo(No* noAtual) {
    return (noAtual == NULL);
}

No* insere(No** noAtual, int elemento) {
    if (isNulo(*noAtual)) {
        No* novoNo = (No *) malloc (sizeof (No));
        novoNo->numero = elemento;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        
        (*noAtual) = novoNo;
        return novoNo;
        } else {
            if (elemento < (*noAtual)->numero) {
            return insere(&(*noAtual)->esquerda, elemento);
        } else {
            return insere(&(*noAtual)->direita, elemento);
        }
    }
}

No* busca(No* noAtual, int elemento) {
    if (isNulo(noAtual)) {
        return NULL;
    } else if (elemento == noAtual->numero) {
        return noAtual;
    } else {
    if (elemento < noAtual->numero) {
        return busca(noAtual->esquerda, elemento);
    } else {
        return busca(noAtual->direita, elemento);
    }
    }
}

void tipoNo(No* noAtual, int elemento) {
    No* noBuscado = busca(noAtual, elemento);
    if (isNulo(noBuscado)) {
        printf("Elemento n�o encontrado! \n");
    } else {
        if (isNulo(noBuscado->esquerda) && isNulo(noBuscado->direita)) {
            printf("O n� %d � um n� terminal. \n", noBuscado->numero);
        } else {
            printf("O n� %d � um n� n�o-terminal. \n", noBuscado->numero);
        }
    }
}

void posOrdem(struct No *raiz){
     if(raiz != NULL){
         posOrdem(raiz->esquerda);
         posOrdem(raiz->direita);
         printf ("Pos ordem [%d] ", raiz->numero);
         
     }
 }
 
 void preOrdem(struct No *raiz){
     if(raiz != NULL){
     	 printf ("Pre ordem [%d] ", raiz->numero);
         preOrdem(raiz->esquerda);
         preOrdem(raiz->direita);
        
         
     }
 }
 
 void emOrdem(struct No *raiz){
     if(raiz != NULL){
     	
         emOrdem(raiz->esquerda);
         printf ("Em ordem[%d] ", raiz->numero);
         emOrdem(raiz->direita);
         
         
     }
 }
 
 
 
int main() {
    Arvore *arvore = (Arvore *) malloc(sizeof(Arvore));

    criaArvore(arvore);
    insere(&arvore->raiz, 10);
    insere(&arvore->raiz, 8);
    insere(&arvore->raiz, 11);
    insere(&arvore->raiz, 5);
    insere(&arvore->raiz, 15);
    insere(&arvore->raiz, 9);
   // tipoNo(arvore->raiz, 4);
    //tipoNo(arvore->raiz, 8);
    
    posOrdem(arvore->raiz);
    printf("\n");
    preOrdem(arvore->raiz);
    printf("\n");
    emOrdem(arvore->raiz);
    printf("\n");
}
