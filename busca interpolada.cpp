#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int vetor [10] = {10, 12, 20, 25, 25, 36, 65, 76, 80, 99};
	int usuario, meio;
	bool encontrado = false;
	int inicial = 0; 
	int contador = 1;
	int final = 9;
	
	
	printf ("***Busca Interpolada***\n");
	printf ("Digite um numero de 0 a 100.\n");
	scanf ("%i", &usuario);
	printf ("Voce digitou o numero [%i] \n", usuario);
	
	while (inicial <= final){
	meio = inicial + (final - inicial) *(usuario - vetor[inicial]) / ((vetor[final]- vetor[inicial]));
	printf("\n O indice do meio foi: %i\n", meio);
    contador++;
    
    	if (vetor[meio] == usuario){
       		 printf ("achou com %i buscas", contador);
       		 encontrado = true;
   			break;
			}
			else{
			printf ("não achou");
			encontrado = true;
			}
    if (encontrado == false){
        printf ("Nao encontrado");
    	}
	}	
}
