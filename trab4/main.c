/*          Modo compilação!
*    $ gcc main.c -o culture -lpthread -lrt -lm 
*    $ ./culture
*/

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <math.h>

#include "src/defines.h"
#include "src/functions.h"



int main(void) {
	
	inicializando();
	
	// criar as threads
	for(int i = 0; i < MAX_THREADS; i++) {	

		int *data = malloc(sizeof(int));
		*data = i;
		
		pthread_create(&ThreadID[i], NULL, swapVetores, (void *) data);	

	}

	//join nas thread
	for(int i = 0; i < MAX_THREADS; i++) 
		pthread_join(ThreadID[i], NULL);
	
	return 0;

}