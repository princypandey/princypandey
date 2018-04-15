#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/types.h>

int main()
{
   int num,i,result,a=0, b=1;
   pid_t p;

   printf("\n Enter the start number:\n");
   scanf("%d", &num);

   if (num<= 0)
      printf("WAARNING :: Enter a number greater than ZERO");
   else
   {
      p= fork();
      if (p == 0)
      {
         printf("Child Process Created\n");
         printf("%d %d",a,b);
         for (i=num;i>0;i--)
         {
            result=num/2;
            printf("result :",&num);
         }
         
      }
      else 
      {
         printf("Parent is in waiting mode\n");
         wait(NULL);
         printf("Parent process ends\n");
      }
   }
   return 0;
}
