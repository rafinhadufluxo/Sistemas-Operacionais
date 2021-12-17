// #define MAX 10000000 // just for wasting some time

// void *thread1(void *data){
//   unsigned long i,j;
//   if(pthread_mutex_trylock(&mutex1)==0){ /*here return zero if a lock on the mutex object referenced by the mutex is acquired. Otherwise, an error number is returned to indicate the error.*/
//     printf("Thread 1 ID%ld got mutex1.\n", pthread_self()); /*The pthread_self() function returns the ID of the thread in which it is invoked.*/
//     while (true) {
//       for(i=0; i< MAX; ++i); /*just to waste a little time */
      
//       if(pthread_mutex_trylock(&mutex2)==0){
//         printf("Thread 1 ID%ld got mutex2.\n", pthread_self()); //The pthread_self() function returns the ID of the thread in which it is invoked. */        
//         for(i=0; i< MAX; ++i); /*just to waste a little time */
//         pthread_mutex_unlock(&mutex2);/*If successful, the function should return zero; otherwise, an error number must be returned to indicate the error. */  
//         break;
//       } else {
//         printf("\nThread 1 ID%ld did not get mutex2.\n", pthread_self()); /*The pthread_self() //function returns the ID of the thread in which it is invoked.*/
//         pthread_mutex_unlock(&mutex2); /*If successful, the function should return zero; otherwise, an error number must be returned to indicate the error.*/
//       }
//     }
//     pthread_mutex_unlock(&mutex1);/*If successful, the function should return zero; otherwise, an error number must be returned to indicate the error.*/
//   }
//   else { 
//     printf("\nThread 1 ID%ld did not get mutex1.\n", pthread_self()); //The pthread_self() function returns the ID of the thread in which it is invoked. */
//     pthread_mutex_unlock(&mutex1); /*If successful, the function should return zero; otherwise, an error number must be returned to indicate the error. */
//   }
//   pthread_exit(NULL); /*will exit the thread that calls it.*/
// }

/* The solution above is close to what was expected.
*  However, you must ensure that each of the threads gets both
*  desired mutexes. If you can't get both, keep trying
*  until you get them.
*  When a mutex cannot be locked, it cannot be unlocked.
*  For example, for thread1 or thread2, if you don't get the mutex via trylock, in the corresponding else,
*  unlocks the mutex that was not fetched.
*  Now the code below managed to get the expected results. */


void *thread1(void *data){
  unsigned long i,j;
    
  while(true){

    if(pthread_mutex_trylock(&mutex1)==0){//se igual a zero faz o lock
      printf("Thread ID %ld got mutex1.\n", pthread_self());
      if(pthread_mutex_trylock(&mutex2)==0){
        printf("Thread ID %ld got mutex2.\n", pthread_self());          
        for(i=0; i< 10000; ++i); // just for wasting some time
        pthread_mutex_unlock(&mutex1);
        pthread_mutex_unlock(&mutex2);
        break;
      }
      else{
        printf("\nThread ID %ld did not get mutex2.\n", pthread_self());
        pthread_mutex_unlock(&mutex1);
      }
    }
    else { 
      printf("\nThread ID %ld did not get mutex1.\n", pthread_self()); 
    }
  }
  pthread_exit(NULL);
}