void inicializando() {

	pthread_barrier_init(&barreira1, NULL, MAX_THREADS); // inicializa barreiras
	pthread_barrier_init(&barreira2, NULL, MAX_THREADS);// inicializa barreiras

	
	for(int i = 0; i < MAX_THREADS; i++){ // inicializa semaforo
		sem_init(&semaforo[i], 0, 0);
    }
	
	
	for(int i = 0; i < (TAMANHO_VETOR - 1); i++) { //seta valores zerados para o vetor
		vetor_velho[i] = 0;
		vetor_novo[i] = 0;
	}
	
	
	vetor_velho[TAMANHO_VETOR - 1] = 1; // ultima posição do vetor recebe 1
	vetor_novo[TAMANHO_VETOR - 1] = 1; 

}


int fatia(int fatia) { /* média entre os valores dos vizinhos à esquerda e à direita */

	int divisao, aux;

	divisao = TAMANHO_VETOR/MAX_THREADS;
	aux = fatia * divisao + 1;
	
	return aux;

}

int fatiaFinal(int fatia, int valorAtual) {

	int resto = TAMANHO_VETOR % MAX_THREADS;
	
	
	if(fatia == MAX_THREADS - 1) { // se for a ultima thread
		if(resto != 0){ 
			return TAMANHO_VETOR - 1;		
        }else{ //no caso em que a última fatia seja menor que as demais
			return TAMANHO_VETOR / MAX_THREADS - 2 + valorAtual;
        }
		
	}
	else{ 
		return TAMANHO_VETOR / MAX_THREADS + valorAtual;
    }
	
}

void imprime(double vetor[TAMANHO_VETOR]) { // imprimir os valores do vetor

	for(int i = 0; i < TAMANHO_VETOR; i++) {
		printf("%lf | ", vetor[i]);
    }
	
	printf("\n");
	
}

void *swapVetores(void* data) {

	int i = *((int*) data);

	for(int k = 0; k < N_INTERACOES; k++) {

		pthread_barrier_wait(&barreira1); // barreira em espera

	    // calcula-se a seguinte recorrência para todos os elementos da posição 1 a N
		for(int j = fatia(i); j < fatiaFinal(i, fatia(i)); j++){
			vetor_novo[j] = (vetor_velho[j-1] + vetor_velho[j+1])/2.0;
        }

		// apenas uma das threads deve fazer o swap entre os dois vetores
		if(pthread_barrier_wait(&barreira2) != 0) {

			imprime(vetor_novo);

			for(int m = 1; m < (TAMANHO_VETOR - 1); m++) {
				vetor_velho[m] = vetor_novo[m];
            }
			
		}

	}
	
}