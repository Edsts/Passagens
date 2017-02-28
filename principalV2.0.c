/* Este programa tem como objetivo realizar reserva de passagens em um avião.
Objetiva avaliar competências sobre vetores e matrizes em C.
- O avião possui 300 lugares
- Devem ser criados 2 vetores com o número de assentos do avião
- Um dos vetores terá o número de cada assento, e o outro terá o nome de cada passageiro
- Deve ser criada uma matriz com o total de assentos
- A matriz inteira deve ser inicializada com valor 0
- UPGRADES DA VERSÃO 2.0 ---> 1) Mostra por escrito o número do assento e se ele está LIVRE OU OCUPADO
2) Diminuição de linhas de código(economia)
3) Alteração de algumas palavras
*/

#include <stdio.h>
main () {
	
	int numAssentos[300] ; //Vetor com número de assentos
	int controlNumAssentos = 0; //Variável de controle para popular o vetor de assentos 
	int cont = 1 ;
	char nomes[300][15] ; //Matriz para os nomes de cada passageiro 
	int controleIndice = 0 ; //Variável de controle e acesso aos índices 
	int ocupados[50][6] = {0} ;	//Matriz para cada assento
	char escolha ; //Variável de escolha para prosseguir com o programa ou não
	int i,j ; //Variável de controle da matriz de assentos
	
	//Inserindo valor ordenado no vetor do número total de assentos
	     for (controlNumAssentos = 0 ; controlNumAssentos < 300 ; controlNumAssentos++ ) { 
	                       numAssentos[controlNumAssentos] = controlNumAssentos + 1 ;
				                                                                         }
    //Fim loop de preenchimento

    //Inicia programa

	do { 
	//Solicita os dados ao usuário
	printf ("\n\nDigite o nome do passageiro : ") ;
	scanf ("%s", nomes[controleIndice]) 	;  
	
	printf("\nDigite o numero do assento desejado: ");
	scanf("%d", &numAssentos[controleIndice]) ;
	
	//Imprime os dados inseridos
	printf("\nNome do passageiro :  %s", nomes[controleIndice]) ;
	printf("\nAssento escolhido : %d",numAssentos[controleIndice]) ;
		
    //Calcula posição do assento na matriz
	int fileira = (numAssentos[controleIndice] - 1)/6 ;
	int posicao = numAssentos[controleIndice] - 1 - fileira * 6 ;
	
	//Verifica se o assento está livre(1) ou ocupado(0)
	if (ocupados[fileira][posicao] == 1)
	        printf("\n\nAssento ocupado") ; 	
                                            
	if (ocupados[fileira][posicao] == 0){
	    printf("\n\nAssento cadastrado com sucesso") ; 	
	    controleIndice++ ;
	    ocupados[fileira][posicao] = 1  ;
	                                   }
	//Pergunta ao usuário se quer continuar ou finalizar o preenchimento dos dados
	printf("\n\nDeseja reservar outro assento? <S/N>") ;
	scanf(" %c", &escolha) ;

	    }
while ((controleIndice < 300) && ((escolha == 'S') || (escolha == 's'))) ;
//Finaliza preenchimento dos assentos

//Mostra os assentos ocupados(1) e livres(0) com seus respectivos números
for (i=0 ; i < 50; i++) {
	printf("\n\n");
	    for (j=0 ; j < 6 ; j++) { 
		  printf ("Assento %d %s | ", cont, ocupados[i][j] == 1? "ocupado" : "livre") ;
		        cont++ ;
			                    }
	        printf("\n\n") ;
	    }
}


