/*  Dica de compilação aqui
*   gcc -o culture deadlock.c -lpthread
*   ./culture
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // using true
#include "src/function.h" // function to initialize the threads
#include "src/thread1.h"
#include "src/thread2.h"


int main(void) {
  pthread_create(&Thread1, NULL, thread1, NULL);
  pthread_create(&Thread2, NULL, thread2, NULL);

  //now join them
  pthread_join(Thread1, NULL);
  printf("\33[0;32m Thread 1 id %ld returned \33[0m\n", Thread1);
  pthread_join(Thread2, NULL);
  printf("\33[0;32m Thread 2 id %ld returned \33[0m\n", Thread2);
  return 1;
}

