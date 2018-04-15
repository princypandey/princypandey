#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>

int main(char* ar[])
{
	int n,fd[2];
	char buf[50];
	
	pid_t pchild;
	pipe(fd);
	pchild=fork();         
         int file= open("input.txt", O_CREAT|O_RDWR, 0777);
         
		 if (file == -1) 
		 {
             printf("File cannot be opened\n");
             exit(1);
         }
         else
         {
           	 write(file,"Hello",5);
		 }
         pchild = fork();
         
         if (pchild == 0) 
		 {
            close(fd[1]);
            read(fd[0], buf, sizeof(buf)) ;
			write(file, buf, strlen(buf) - 1);
               
            close(fd[0]);
            close(file);
         }
         
}

