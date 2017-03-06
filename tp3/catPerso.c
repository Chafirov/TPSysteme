#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE_BUF 10

ssize_t readWrite(int fdin, int fdout, char* buf, size_t count){

	ssize_t nbChar = read(fdin, buf, count);
	write(fdout, buf, nbChar);

	return nbChar;
	
}

int main(int argc, char** argv){
	
	int fd;
 
	if(argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = STDIN_FILENO;
	
	char buf[SIZE_BUF];

	while(readWrite(fd, STDOUT_FILENO, buf, SIZE_BUF) > 0)
	
	close(fd);

	return 0;
}
