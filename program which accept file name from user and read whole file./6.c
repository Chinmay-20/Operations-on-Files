#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int x=0;
int main(int argc,char* argv[])
{
	int fd=0,numread=0,num=0;
	char buf[512]="\0";

	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		printf("the error no is %d\n",errno);
		return -1;
	}
	printf("The file is successfully open with fd %d\n",fd);
	while((numread=read(fd,buf,sizeof(buf)))!=0)
	{
		write(1,buf,numread);
		memset(buf,0,sizeof(buf));
	}
	if(numread==-1)
	{
		perror("read");
		printf("The errno is %d\n",errno);
		close(fd);
		return -1;
	}
	
	close(fd);
	return 0;
}
/*
chinmay@chinmay:~/Desktop/Assignment2$ gcc 6.c -o myexe
chinmay@chinmay:~/Desktop/Assignment2$ ./myexe 6.c
The file is successfully open with fd 3
#hchinmay@chinmay:~/Desktop/Assignment2$ gcc 6.c -o myexe
chinmay@chinmay:~/Desktop/Assignment2$ ./myexe 6.c
The file is successfully open with fd 3
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int x=0;
int main(int argc,char* argv[])
{
	int fd=0,numread=0,num=0;
	char buf[512]="\0";

	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		printf("the error no is %d\n",errno);
		return -1;
	}
	printf("The file is successfully open with fd %d\n",fd);
	while((numread=read(fd,buf,sizeof(buf)))!=0)
	{
		write(1,buf,numread);
		memset(buf,0,sizeof(buf));
	}
	if(numread==-1)
	{
		perror("read");
		printf("The errno is %d\n",errno);
		close(fd);
		return -1;
	}
	
	close(fd);
	return 0;
}
chinmay@chinmay:~/Desktop/Assignment2$ 
*/
