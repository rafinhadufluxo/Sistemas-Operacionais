void *filosofo(void *num){
    while(1){
      int *i = num;
      sleep(1);
      agarraGarfo(*i);
      sleep(1);
      deixaGarfo(*i);
      
    }
}

void agarraGarfo(int nfilosofo){
   sem_wait(&mutex);
   estado[nfilosofo] = FOME;
   printf("Filosofo %d tem fome.\n", nfilosofo+1);
   //+1 para imprimir filosofo 1 e nao filosofo 0
   testar(nfilosofo);
   sem_post(&mutex);
   sem_wait(&S[nfilosofo]);
   sleep(1);
}

void deixaGarfo(int nfilosofo){
   sem_wait(&mutex);
   estado[nfilosofo]=PENSAR;
   printf("Filosofo %d deixou os garfos %d e %d.\n", nfilosofo+1, ESQUERDA+1, nfilosofo+1);
   printf("Filosofo %d esta a pensar.\n", nfilosofo+1);
   testar(ESQUERDA);
   testar(DIREITA);
   sem_post(&mutex);
}

void testar(int nfilosofo){
   if(estado[nfilosofo]==FOME && estado[ESQUERDA]
 !=COMER && estado[DIREITA]!=COMER)
   {
      estado[nfilosofo]=COMER;
      sleep(2);
      printf("Filosofo %d agarrou os garfos %d e %d.\n", nfilosofo+1, ESQUERDA+1, nfilosofo+1);
      printf("Filosofo %d esta a comer.\n", nfilosofo+1);
      sem_post(&S[nfilosofo]);
   }
}