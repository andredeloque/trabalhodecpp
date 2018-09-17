#include <stdlib.h>
#include <stdio.h>

int main (){
	
	int opcao, usuario, meio, i;
	int sair = 1;
	int encontrado = -1;
	int vetor [10] = {10, 12, 20, 25, 25, 36, 65, 76, 80, 99};
	int inicial = 0; 
	int final = 9;
	int contador = 1;
	
		printf ("1- Busca sequencial:\n2- Sequencial e indexada:\n3- Busca binaria:\n4- Busca interpolada:\n0- SAIR:\n");
		scanf ("%i", &opcao);
	
	
	while (opcao != 0){
		
	
		
		switch (opcao){
		
		if (usuario > 100){
					printf ("o numero [%i] eh maior que 100. \n\n\ ", usuario);
					return 1;
				}
				if (usuario < 0){
					printf ("o numero [%i] eh menor que 0\n\n\ ", usuario);
					return 1;
				}
			
			case 0:
				sair = 0;
				break;
				
			case 1:
			//	system("cls");
				printf ("***Busca Sequencial***\n");	
				printf ("Digite um numero de 0 a 100.\n");
				scanf ("%i", &usuario);
				
				 	for ( i=0; i<10; i++){
							if (vetor[i] == usuario){
								printf ("Numero [%d] encontrado, na posicao %d\n",vetor[i], i);
						 		encontrado = i;
						 		opcao = 1;
						 		return 0;
							}
						}
							if(encontrado == -1){
								printf("Elemento nao encontrado.\n");
								opcao = 1;
								return 0; 
						}
			case 2:
			//	system("cls");
				printf ("***Sequencial Indexada***\n");
				printf ("Digite um numero de 0 a 100.\n");
				scanf ("%i", &usuario);
			
			 		for ( i=0; i<10; i++){
						if (vetor[i] == usuario){
							printf ("Numero [%d] encontrado, na posicao %d\n",vetor[i], i);
					 		encontrado = i;
					 		opcao = 1;
					 		return 0;
						}
						if ( vetor[i] > usuario ){
						printf ("nao encontrado ");
						encontrado = i;
						opcao = 1;
						return 0;
						}
					}
					if(encontrado == -1){
						printf("Numero nao encontrado.\n");
						opcao = 1;
						return 0;
					}	
			case 3:
			//	system("cls");
				printf ("***Busca Binaria***\n");
				printf ("Digite um numero de 0 a 100.\n");
				scanf ("%i", &usuario);
				printf ("Voce digitou o numero [%i] \n", usuario);
				
				while (inicial <= final ){
					meio = (inicial+final)/2;
					
				    if (vetor[meio] == usuario){
				        encontrado = meio;
				    	printf ("%i encontrado depois de %i buscas", usuario, contador);
				    	opcao = 1;
				    	return 0;
				    }
				    
					if (vetor[meio] > usuario){
					    final = meio-1;
					}
					if (vetor[meio] < usuario){
					    inicial = meio+1;
					}
						
						contador ++;
				}
				
				
				if (encontrado == -1){
				    printf ("Numero %i nao encontrado", usuario);
				    opcao = 1;
				    return 0;
				}
			case 4:
		//	system("cls");
			printf ("***Busca Interpolada***\n");
			printf ("Digite um numero de 0 a 100.\n");
			scanf ("%i", &usuario);
			printf ("Voce digitou o numero [%i] \n", usuario);
			
			while (inicial <= final){
			meio = inicial + (final - inicial) * (usuario - vetor[inicial]) / ((vetor[final] - vetor[inicial]));
			printf("\n O indice do meio foi: %i\n", meio);
		    contador++;
		    
		    	if (vetor[meio] == usuario){
		       		printf ("achou com %i buscas", contador);
		       		encontrado = meio;
		       		opcao = 1;
		   			return 0;
		   			
					}
					else{
					printf ("não achou");
					encontrado = meio;
					opcao = 1;
					return 0;
					}
					
		    if (encontrado == -1){
		        printf ("Nao encontrado");
		        opcao = 1;
		        return 0;
		        
		    default:
		    	printf ("Digite Novamente:");
		    	return 0;
		    	}
			}		
		}
		
	}
}
