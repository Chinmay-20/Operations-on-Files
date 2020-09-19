#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<time.h> 	
//#include<sys/types.h>
//#include<sys/sysmacros.h>


int main(int argc,char* argv[])
{
	int fd=0,ret=0;
	
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		perror("open");
	}
	struct stat mystruct;
	
	ret=stat(argv[1],&mystruct);
	if(ret==-1)
	{
		perror("stat");
		close(fd);
		return -1;
	}
	/*
	dev_t     st_dev;         /* ID of device containing file */
         //      ino_t     st_ino;         /* Inode number */
           //    mode_t    st_mode;        /* File type and mode */
             //  nlink_t   st_nlink;       /* Number of hard links */
               //uid_t     st_uid;         /* User ID of owner */
               //gid_t     st_gid;         /* Group ID of owner */
               //dev_t     st_rdev;        /* Device ID (if special file) */
               //off_t     st_size;        /* Total size, in bytes */
               //blksize_t st_blksize;     /* Block size for filesystem I/O */
               //blkcnt_t  st_blocks;   */   /* Number of 512B blocks allocated */
               
	printf("ID of device containing file is %ld\n",mystruct.st_dev);
	printf("Inode number is %ld\n",mystruct.st_ino);
	printf("File type and mode is %o\n",mystruct.st_mode);
	printf("Number of hard links is/are %ld\n",mystruct.st_nlink);
	printf("User ID of owner is %d\n",mystruct.st_uid);
	printf("Group ID of owner is %d\n",mystruct.st_gid);
	printf("Device Id is %ld\n",mystruct.st_rdev);
	printf("Total size in bytes are %ld\n",mystruct.st_size);
	printf("Block size for file stream is %ld\n",mystruct.st_blksize);
	printf("Number of 4096B blocks allocated are %ld\n",mystruct.st_blocks);
	printf("the time of the last access of file data is %s\n",ctime(&mystruct.st_ctime));
	printf("the time of the last modification of file data is %s\n",ctime(&mystruct.st_mtime));
	printf("the time of the last statuc change timestamp is %s\n",ctime(&mystruct.st_ctime));
	
	int x=gnu_dev_major(mystruct.st_dev);
	printf("gnu_dev_major is %d \n ",x);
	
	close(fd);
}

/*
chinmay@chinmay:~/Desktop/Assignment2$ make build
gcc 3.c -o myexe
chinmay@chinmay:~/Desktop/Assignment2$ make args1=3.c run
./myexe 3.c 
ID of device containing file is 2073
Inode number is 3801155
File type and mode is 100664
Number of hard links is/are 1
User ID of owner is 1000
Group ID of owner is 1000
Device Id is 0
Total size in bytes are 2024
Block size for file stream is 4096
Number of 4096B blocks allocated are 8
the time of the last access of file data is Sun Sep 13 09:29:06 2020

the time of the last modification of file data is Sun Sep 13 09:29:06 2020

the time of the last statuc change timestamp is Sun Sep 13 09:29:06 2020

chinmay@chinmay:~/Desktop/Assignment2$ stat 3.c
  File: 3.c
  Size: 2024      	Blocks: 8          IO Block: 4096   regular file
Device: 819h/2073d	Inode: 3801155     Links: 1
Access: (0664/-rw-rw-r--)  Uid: ( 1000/ chinmay)   Gid: ( 1000/ chinmay)
Access: 2020-09-13 09:34:10.748612644 +0530
Modify: 2020-09-13 09:29:06.243439013 +0530
Change: 2020-09-13 09:29:06.243439013 +0530
 Birth: -
chinmay@chinmay:~/Desktop/Assignment2$ 

*/
