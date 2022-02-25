/*
*   Compile code :
*               $ gcc main.c -o culture -pthread
*               $ ./culture
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "src/defines.h" 

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_variable1   = PTHREAD_COND_INITIALIZER;
pthread_cond_t  condition_variable2   = PTHREAD_COND_INITIALIZER;

/*global variables, are thread good*/
int count = 0;
int SoThreadBOA = 0;

int main(){
   pthread_t thread0, thread1, thread2;

   pthread_create( &thread0, NULL, &functionCount0, NULL);
   pthread_create( &thread1, NULL, &functionCount1, NULL);
   pthread_create( &thread2, NULL, &functionCount2, NULL);

   pthread_join( thread0, NULL);
   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   printf("Final count: %d\n",count);

   pthread_mutex_destroy(&count_mutex);

   return 1;
}

/**** here will show functions of three threads. let's go go 🚀 */
#include "src/functions.h"