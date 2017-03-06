#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


pthread_mutex_t mutex;

void try(int err){
	if(err != 0){
		printf(strerror(err));
		exit(EXIT_FAILURE);
	}
}

void* concu(void* message){
	char* nom = (char*)message;
	while(1){
		printf("%s travaille sans la ressource\n", nom);
		sleep(3);

		
		printf("%s a besoin de la ressouce\n", nom);

		#if AVEC_MUTEX
		pthread_mutex_lock(&mutex);
		#endif
		printf("%s travaille avec la ressource\n", nom);
		printf("%s n'a plus besoin de la ressource\n", nom);
	
		#if AVEC_MUTEX
		pthread_mutex_unlock(&mutex);
		#endif
	
		sleep(2);
	}	
	return NULL;
}


int main(){
	pthread_t thread1;
	pthread_t thread2;

	pthread_mutex_init(&mutex, NULL);

	try(pthread_create(&thread1, NULL, concu, (void*)"thread1"));
	try(pthread_create(&thread2, NULL, concu, (void*)"thread2"));
	
	pthread_join(thread1, NULL);	
	pthread_join(thread2, NULL);	
	
	return 0;
}
