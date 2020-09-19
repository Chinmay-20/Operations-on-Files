#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(int argc,char* argv[])
{

	int fd=0;
	if((strcmp(argv[1],"--h")==0) || (strcmp(argv[1],"--H")==0) ||(strcmp(argv[1],"--help")==0))
	{
		printf("exe_name file_name\n");
		return -1;
	}
	if(argc!=2)
	{
		printf("Invalid Arguments\n");
		printf("exe_name file_name\n");
		return -1;
	}
	
	fd=open(argv[1],O_RDWR);
	if(fd==-1)
	{
		perror("Open");
		printf("The errno is %d\n",errno);
	}
	
	printf("the file is successfully opened with file descriptor %d\n",fd);
	close(fd);
}
/*
chinmay@chinmay:~/Desktop/Assignment2$ make build
gcc 1.c -o myexe
chinmay@chinmay:~/Desktop/Assignment2$ make args1="1.c" run
./myexe 1.c
the file is successfully opened with file descriptor 3
chinmay@chinmay:~/Desktop/Assignment2$ make clean
rm myexe
chinmay@chinmay:~/Desktop/Assignment2$ 
*/
