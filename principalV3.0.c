/* Este programa tem como objetivo realizar reserva de passagens em um avião.
Objetiva avaliar competências sobre vetores e matrizes em C.
- O avião possui 300 lugares
- Devem ser criados 2 vetores com o número de assentos do avião
- Um dos vetores terá o número de cada assento, e o outro terá o nome de cada passageiro
- Deve ser criada uma matriz com o total de assentos
- A matriz inteira deve ser inicializada com valor 0
- UPGRADES DA VERSÃO 3.0 ---> 1)Acentuação adicionada 
2) Acréscimo de algumas condicionais para validação de dados */


#include <stdio.h>
#include <locale.h>
main () {
	
	int numAssentos[300] ; //Vetor com número de assentos
	int controlNumAssentos = 0; //Variável de controle para popular o vetor de assentos 
	char nomes[300][15] ; //Matriz para os nomes de cada passageiro 
	int controleIndice = 0 ; //Variável de controle e acesso aos índices (para indicar a posição do vetor utilizada)
	int ocupados[50][6] = {0} ;	//Matriz para cada assento
	char escolha1,escolha2 ; //Variáveis de escolha para responder as perguntas do sistema sobre o prosseguimento
	int cont = 1 ; //Variável utilizada para contar o número do assento, no loop que exibe a listagem de assentos
	int temp = 0 ; //variável de armazenamento temporário, para validar o assento digitado em um loop
	int i,j ; //Variável de controle da matriz de assentos
	
	//Inserindo valor ordenado no vetor do número total de assentos
	     for (controlNumAssentos = 0 ; controlNumAssentos < 300 ; controlNumAssentos++ ) { 
	                       numAssentos[controlNumAssentos] = controlNumAssentos + 1 ;
				                                                                         }
    //Fim loop de preenchimento

    //Inicia programa

	do { 
	
	//Função para utilizar acentuação de língua portuguesa
	setlocale (LC_ALL, "portuguese") ;
	
	//Limpa buffer
	fflush(stdin) ;
	
	//Solicita os dados ao usuário
	printf ("\n\nDigite o nome do passageiro : ") ;
	gets(nomes[controleIndice]) 	;  
	
	/*Armazena o número do assento digitado em uma variável temporária. Se o assento desejado for menor que 1 e maior que 300, entra em loop, até que o usuário digite um número válido.
	Quando o usuário digitar um número válido, esse número é passado para o vetor de assentos. */
	
	printf("\nDigite o número do assento desejado: ");
	scanf("%d", &temp) ;
	
	while((temp <1) || (temp>300)){
		
  printf("\n\nNúmero de assento inválido. Digite uma posição entre 1 e 300.") ;
	printf("\n\nDigite o número do assento desejado: ");
	
			scanf("%d", &temp) ;
		
						}
	

	numAssentos[controleIndice] = temp ;

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
	                                   
	printf("\n\nDeseja ver a listagem dos assentos ? <S/N> : ") ;
	scanf(" %c", &escolha1) ; 
	
	if((escolha1 == 'S') || (escolha1 == 's')) {
		
		
		//Mostra os assentos com status ocupado(1) ou livre(0) com seus respectivos números 
	for (i=0 ; i < 50; i++) {
		printf("\n\n");
			for (j=0 ; j < 6 ; j++) { 
		  		printf (" Assento %d - %s | ", cont,ocupados[i][j] == 1? "ocupado" : "livre") ;
		        cont++ ;
			                    }
	        printf("\n\n") ;
	    }
		
		//Quando a variável de contagem chegar a 300 no fim do loop, ela será reiniciada com o valor 1, para rodar o mesmo loop posteriormente se necessário
		if(cont = 300){
		
			cont = 1 ;
			}
	}                              
	                                   
	                                   
	//Pergunta ao usuário se quer continuar ou finalizar o preenchimento dos dados
	printf("\n\nDeseja reservar outro assento? <S/N>") ;
	scanf(" %c", &escolha2) ;

	    }
while ((controleIndice < 300) && ((escolha2 == 'S') || (escolha2 == 's'))) ;
//Fim do preenchimento dos assentos


printf("\n\nPrograma finalizado !!  ") ;


}


	



