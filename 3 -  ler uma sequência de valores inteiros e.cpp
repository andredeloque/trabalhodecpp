//3) Escreva um algoritmo para ler uma sequência de valores inteiros e, para cada valor
//lido, incluí-lo em uma árvore binária de busca. O valor 0 (zero) encerra a entrada de
//dados.



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
        if (ehPar%2==0){ //se o no tem so um filho
         	printf ("Esse numero eh par meu chapa [%d] \n", noAtual->numero);
         	contador ++;
		}
	}
}

int naoDigiteZero(Arvore* arvore){
	int digitado = 1;
	while(digitado != 0){
		printf("Digite um numero: ");
		scanf("%i", &digitado);
		if (digitado%2==0){
			insere(&arvore->raiz, digitado);
		}
		
	}
}


int main() {
    Arvore *arvore = (Arvore *) malloc(sizeof(Arvore));

    criaArvore(arvore);
    printf("Salve");
    naoDigiteZero(arvore);
    preOrdem(arvore->raiz);
	

}
