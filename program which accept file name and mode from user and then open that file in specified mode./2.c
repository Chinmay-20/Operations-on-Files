#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	int fd=0,ret=0,accmode=0,per=0;
	if((strcmp(argv[1],"--h")==0) || (strcmp(argv[1],"--H")==0) ||(strcmp(argv[1],"--help")==0))
	{
		printf("exe_name file_name mode_to_open\n");
		return -1;
	}
	if(argc!=3)
	{
		printf("Invalid Arguments\n");
		printf("exe_name file_name mode_to_open\n");
		return -1;
	}
	if((strcmp(argv[2],"O_RDONLY"))==0)
	{
		per=0;
	}
	else if((strcmp(argv[2],"O_WRONLY"))==0)
	{
		per=1;
	}
	else if((strcmp(argv[2],"O_RDWR"))==0)
	{
		per=2;
	}
	fd=open(argv[1],per);
	if(fd==-1)
	{
		perror("open");
		printf("The error no is %d\n",fd);
	}
	
	
	ret=fcntl(fd,F_GETFL);
	if(ret==-1)
	{
		perror("fcntl");
		printf("the error no is %d\n",errno);
	}
	accmode=ret & O_ACCMODE;
	printf("accmode  and ret is %d & %d\n",accmode,ret);
	if(accmode==0)
	{
		printf("The file is successfully opened with file descriptor %d and in mode O_RDONLY\n",fd);
	}
	else if(accmode==1)
	{
		printf("The file is successfully opened with file descriptor %d and in mode O_WRONLY\n",fd);
	}
	else if(accmode==2)
	{
		printf("The file is successfully opened with file descriptor %d and in mode O_RDWR\n",fd);
	}
	
	close(fd);
	
	return 0;
}

/*
chinmay@chinmay:~/Desktop/Assignment2$ make build
gcc 2.c -o myexe
chinmay@chinmay:~/Desktop/Assignment2$ make args1="2.c" args2="O_WRONLY" run
./myexe 2.c O_WRONLY
accmode  and ret is 1 & 32769
The file is successfully opened with file descriptor 3 and in mode O_WRONLY
chinmay@chinmay:~/Desktop/Assignment2$ make args1="2.c" args2="O_RDONLY" run
./myexe 2.c O_RDONLY
accmode  and ret is 0 & 32768
The file is successfully opened with file descriptor 3 and in mode O_RDONLY
chinmay@chinmay:~/Desktop/Assignment2$ make args1="2.c" args2="O_RDWR" run
./myexe 2.c O_RDWR
accmode  and ret is 2 & 32770
The file is successfully opened with file descriptor 3 and in mode O_RDWR
chinmay@chinmay:~/Desktop/Assignment2$ 
*/
