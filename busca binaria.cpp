#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int vetor [10] = {10, 12, 20, 25, 25, 36, 65, 76, 80, 99};
	int usuario, meio;
	bool encontrado = false;
	int inicial = 0; 
	int contador = 1;
	int final = 9;
	
	
	printf ("***Busca Binaria***\n");
	printf ("Digite um numero de 0 a 100.\n");
	scanf ("%i", &usuario);
	printf ("Voce digitou o numero [%i] \n", usuario);
	
	if (usuario > 100){
		printf ("o numero [%i] eh maior que 100. \n\n\ ", usuario);
		return 1;
	}
	if (usuario < 0){
		printf ("o numero [%i] eh menor que 0\n\n\ ", usuario);
		return 1;
	}
	
	while (inicial <= final ){
		meio = (inicial+final)/2;
		
	    if (vetor[meio] == usuario){
	        encontrado = true;
	    	printf ("%i encontrado depois de %i buscas", usuario, contador);
	    	break;
	    }
	    
		if (vetor[meio] > usuario){
		    final = meio-1;
		}
		if (vetor[meio] < usuario){
		    inicial = meio+1;
		}
			
			contador ++;
	}
	
	
	if (encontrado == false){
	    printf ("Numero %i nao encontrado", usuario);
	}
}
