//1) Considere estruturas de árvores binárias que armazenam valores inteiros e
//implemente um método que retorne a quantidade de nós que guardam os
//números pares.


#include <stdio.h>
#include <stdlib.h>


int contador = 0;
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
        printf("Elemento não encontrado! \n");
    } else {
        if (isNulo(noBuscado->esquerda) && isNulo(noBuscado->direita)) {
            printf("O nó %d é um nó terminal. \n", noBuscado->numero);
        } else {
            printf("O nó %d é um nó não-terminal. \n", noBuscado->numero);
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
 
 /*bool temSoUmFilho(No* noAtual) {
 	if () {
 		return false;
	 } else {
	 	return true;
	 }
 }*/
 
 
int encontrarQtdNumerosPares(No* noAtual) {
	int ehPar = 0;
	if(noAtual != NULL){
        encontrarQtdNumerosPares(noAtual->esquerda);
        encontrarQtdNumerosPares(noAtual->direita);
         
         
        ehPar = noAtual -> numero;
        if (temUmFilho(noAtual){ //se o no tem so um filho
         	printf ("Esse só tem um filho [%d] \n", noAtual->numero);
         	contador ++;
		}
	}
}

int temUmFilho (No* noAtual){
	if (noAtual == NULL || (noAtual->esquerda == NULL && noAtual->direita == NULL))
    return 0;
    else
    printf(encontrarQtdNumerosPares);
}


int main() {
    Arvore *arvore = (Arvore *) malloc(sizeof(Arvore));

    criaArvore(arvore);
    insere(&arvore->raiz, 11);
    insere(&arvore->raiz, 4);
    insere(&arvore->raiz, 7);
    insere(&arvore->raiz, 15);
    insere(&arvore->raiz, 14);
    insere(&arvore->raiz, 17);
    insere(&arvore->raiz, 9);
    insere(&arvore->raiz, 23);
    insere(&arvore->raiz, 12);

	//int quantidadeNumerosPares = encontrarQtdNumerosPares(&arvore->raiz);
	//printf("A quantidade de numeros pares é: %d!", quantidadeNumerosPares);
	encontrarQtdNumerosPares(arvore->raiz);
	printf("Sao %d pares \n", contador);
	temUmFilho(arvore->raiz);
	

}
