#include <stdio.h>
#include <stdlib.h>

int main (){
	int vetor [10] = {10, 12, 20, 25, 25, 36, 65, 76, 80, 99};
	int usuario;
	int encontrado = -1;
	
	printf ("Digite um numero de 0 a 100.\n");
	scanf ("%i", &usuario);

 		for (int i=0; i<10; i++){
			if (vetor[i] == usuario){
				printf ("Numero [%d] encontrado, na posicao %d\n",vetor[i], i);
		 		encontrado = i;
		 		break;
			}
			if ( vetor[i] > usuario ){
			printf ("nao encontrado ");
			encontrado = i;
			}
		}
		if(encontrado == -1){
			printf("Numero nao encontrado.\n");
		}	
}
