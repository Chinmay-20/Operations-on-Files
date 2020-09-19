#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int x=0;
int main(int argc,char* argv[])
{
	int fd=0,bytes=atoi(argv[2]),numread=0,num=0;
	char buf[1024]="\0";

	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		printf("the error no is %d\n",errno);
		return -1;
	}
	printf("The file is successfully open with fd %d\n",fd);
	while(num<=bytes)
	{
	numread=read(fd,buf,bytes);
	if(numread==-1)
	{
		perror("read");
		printf("The errno is %d\n",errno);
		close(fd);
		return -1;
	}
	printf("The number of bytes read are %d\n",numread);
//	buf[bytes+1]="\0";
	printf("The data read is %s\n",buf);
	num=num+numread;
	}
	
	close(fd);
	return 0;
}
/*chinmay@chinmay:~/Desktop/Assignment2$ make build
gcc 4.c -o myexe
4.c: In function ‘main’:
4.c:10:17: warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
   10 |  int fd=0,bytes=atoi(argv[2]),numread=0,num=0;
      |                 ^~~~
chinmay@chinmay:~/Desktop/Assignment2$ make args1=4.c args2=700 run
./myexe 4.c 700
The file is successfully open with fd 3
The number of bytes read are 700
The data read is #include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int x=0;
int main(int argc,char* argv[])
{
	int fd=0,bytes=atoi(argv[2]),numread=0,num=0;
	char buf[1024]="\0";

	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		printf("the error no is %d\n",errno);
		return -1;
	}
	printf("The file is successfully open with fd %d\n",fd);
	while(num!=bytes)
	{
	numread=read(fd,buf,bytes);
	if(numread==-1)
	{
		perror("read");
		printf("The errno is %d\n",errno);
		close(fd);
		return -1;
	}
	printf("The number of bytes read are %d\n",numread);
//	buf[bytes+1]="\0";
	printf("The data read is %s\n",buf);
	num=num+numread;
	}
	
	close(fd);
	return 0;
}
	

chinmay@chinmay:~/Desktop/Assignment2*/
	
