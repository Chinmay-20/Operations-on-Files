#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(int argc,char* argv[])
{
	int fd=0,numwrite=0;
	//printf("the arg len is %ld\n",strlen(argv[2]));
	//printf("the arg is %s\n",argv[2]);
	fd=open(argv[1],O_WRONLY|O_APPEND);
	if(fd==-1)
	{
		perror("open");
		printf("The error no is %d\n",errno);

		return -1;
	}
	
	printf("The file is successfully open with fd %d\n",fd);	
	
	
	numwrite=write(fd,argv[2],strlen(argv[2]));
	if(numwrite==-1)
	{
		perror("write");
		printf("The error no is %d\n",errno);
		return -1;
	}
	
	printf("The number of bytes successfully written are %d\n",numwrite);
	
	close(fd);
	return 0;
}
/*
hinmay@chinmay:~/Desktop/Assignment2$ make build
gcc 7.c -o myexe
chinmay@chinmay:~/Desktop/Assignment2$ ls
1.c  2.c  4.c  5.c  7.c  Demo.txt  makefile  myexe
chinmay@chinmay:~/Desktop/Assignment2$ make args1="/home/chinmay/Desktop/Demo.txt" args2="abcdefgh" run
./myexe /home/chinmay/Desktop/Demo.txt abcdefgh
open: No such file or directory
The error no is 2
make: *** [makefile:5: run] Error 255
chinmay@chinmay:~/Desktop/Assignment2$ make args1="/home/chinmay/Desktop/Assignment2/Demo.txt" args2="abcdefgh" run
./myexe /home/chinmay/Desktop/Assignment2/Demo.txt abcdefgh
The file is successfully open with fd 3
The number of bytes successfully written are 8
chinmay@chinmay:~/Desktop/Assignment2$ ^C
chinmay@chinmay:~/Desktop/Assignment2$ 
*/
