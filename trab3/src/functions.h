void *functionCount0(){
    for(;;){
        pthread_mutex_lock( &count_mutex );

        if(SoThreadBOA >= MAX){
            pthread_mutex_unlock(&count_mutex);
            pthread_cond_signal(&condition_variable1);
            pthread_cond_signal(&condition_variable2);
            pthread_exit(NULL);
        }

        int nth = SoThreadBOA % Number_Threads;
      
       
        if(nth == 0){
            SoThreadBOA ++;
            printf("Thread 0 | global = %d \n", SoThreadBOA);
            pthread_mutex_unlock(&count_mutex);
        } else if(nth == 1){
            pthread_mutex_unlock(&count_mutex);
            pthread_cond_signal(&condition_variable1);
        }else{
            pthread_mutex_unlock(&count_mutex);
            pthread_cond_signal(&condition_variable2);
        }
    }
    
}

// Write numbers 4-7
// Condition of if statement has been met. 
// Signal to free waiting thread by freeing the mutex.
// Note: functionCount0() is now permitted to modify "count".
void *functionCount1(){
    unsigned long i;
    for(;;){
        pthread_mutex_lock(&count_mutex);

        if(SoThreadBOA >= MAX ){
	        pthread_mutex_unlock( &count_mutex );
            pthread_exit(NULL);
        }
        pthread_cond_wait(&condition_variable1, &count_mutex);

        if (SoThreadBOA >= MAX){
            pthread_mutex_unlock(&count_mutex);
            pthread_exit(NULL);
        }
        
        SoThreadBOA++;
        printf("Thread 1 | global = %d \n", SoThreadBOA);

        pthread_mutex_unlock(&count_mutex);
    }
}

void *functionCount2(){
    unsigned long i;
    for(;;){
        pthread_mutex_lock( &count_mutex );

        if( SoThreadBOA >= MAX ){
	        pthread_mutex_unlock( &count_mutex );
            pthread_exit(NULL);
        }
        pthread_cond_wait(&condition_variable2, &count_mutex);

        if (SoThreadBOA >= MAX){
            pthread_mutex_unlock(&count_mutex);
            pthread_exit(NULL);
        }
        
        SoThreadBOA++;
        
        printf("Thread 2 | global = %d \n", SoThreadBOA);
        pthread_mutex_unlock(&count_mutex);
    }
}