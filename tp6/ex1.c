#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define N 10

void try(int err){
	if(err != 0){
		printf(strerror(err));
		exit(EXIT_FAILURE);
	}
}

void* pingpong(void* message){
	for (int i = 1; i < N; i++){
		printf("%s\n", (char*)message);
		sleep(1);
	}
	return NULL;
}


int main(){
	pthread_t thread1;
	pthread_t thread2;

	try(pthread_create(&thread1, NULL, pingpong, (void*)"ping"));
	try(pthread_create(&thread2, NULL, pingpong, (void*)"pong"));
	
	pthread_join(thread1, NULL);	
	pthread_join(thread2, NULL);	
	
	return 0;
}
