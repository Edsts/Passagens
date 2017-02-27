
/* Este programa tem como objetivo realizar reserva de passagens em um avião.
Objetiva avaliar competências sobre vetores e matrizes em C.

- O avião possui 300 lugares
- Devem ser criados 2 vetores com o número de assentos do avião
- Um dos vetores terá o número de cada assento, e o outro terá o nome de cada passageiro
- Deve ser criada uma matriz com o total de assentos
- A matriz inteira deve ser inicializada com valor 0

*/


#include <stdio.h>

main () {
	
	
	int numAssentos[300] ; //Vetor com número de assentos
	int controlNumAssentos = 0; //Variável de controle para popular o vetor de assentos 
	char nomes[300][15] ; //Matriz para os nomes de cada passageiro 
	int controleIndice = 0 ; //Variável de controle e acesso aos índices 
	int ocupados[50][6] = {0} ;	//Matriz 50x6 para localização de cada assento
	char escolha ; //Variável de escolha para prosseguir com o programa ou não
	int i,j ; //Variável de controle da matriz de assentos
	
	
	//Inserindo valor ordenado no vetor do número total de assentos
	
	for (controlNumAssentos = 0 ; controlNumAssentos < 300 ; controlNumAssentos++ ) { 
	
					numAssentos[controlNumAssentos] = controlNumAssentos + 1 ;
										
										}
						
					                                    
					//Fim loop de preenchimento


	//Inicia programa

	do { 
	
	//Solicita ao usuário o nome e o número do assento desejado
	
	printf ("\n\nDigite o nome do passageiro : ") ;
	scanf ("%s", nomes[controleIndice]) 	;  
	
	printf("\nDigite o numero do assento requerido : ");
	scanf("%d", &numAssentos[controleIndice]) ;
	
	

  //Imprime os dados informados pelo usuário 

	printf("\nNome do passageiro :  %s", nomes[controleIndice]) ;
	
	
	printf("\nAssento escolhido : %d",numAssentos[controleIndice]) ;
		


	//Calcula posição do assento na matriz
	
	int fileira = (numAssentos[controleIndice] - 1)/6 ;
	int posicao = numAssentos[controleIndice] - 1 - fileira * 6 ;
	
	
	
//Verifica se o assento está livre(0) ou ocupado(1)

	if (ocupados[fileira][posicao] == 1)  {
	
		 
		 printf("\n\nAssento já reservado, por gentileza escolha outro") ; 	
		 
		 
	                                       }
	
	
	if (ocupados[fileira][posicao] == 0){
	
	printf("\n\nAssento reservado com sucesso") ; 	
	controleIndice++ ;
	ocupados[fileira][posicao] = 1 ;
	                                    }
	
	

  //Pergunta ao usuário se deseja continuar

	printf("\n\nDeseja continuar ? <S/N>") ;
	scanf(" %c", &escolha) ;
	
	}

while ((controleIndice < 300) && ((escolha == 'S') || (escolha == 's'))) ;

//Fim preenchimento dos dados

//Percorre a matriz e mostra os assentos ocupados(1) e livres(0)

for (i=0 ; i < 50; i++) {
	
		for (j=0 ; j < 6 ; j++) { 
		
		    printf ("%d", ocupados[i][j]) ;
		
		                        }
	
	                          printf("\n\n") ;
	
		                 	}


}


