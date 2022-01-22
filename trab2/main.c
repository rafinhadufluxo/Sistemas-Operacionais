// Para compilar: gcc -pthread main.c -o culture

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h> //Sleep(1000); => 1000 milliseconds
#include "src/defines.h"
#include "src/function.h" 


int main() {
   int i;
   pthread_t thread_id[N]; //ID de threads
   sem_init(&mutex,0,1);
   
   for(i=0;i<N;i++)
      sem_init(&S[i],0,0);
   
   for(i=0;i<N;i++){
      pthread_create(&thread_id[i], NULL, filosofo, &nfilosofo[i]);//criando as threads
      printf("Filosofo %d esta a pensar.\n",i+1);
   }
   
   for(i=0;i<N;i++)
   pthread_join(thread_id[i],NULL); //para fazer a junção das threads
   return(0);
}