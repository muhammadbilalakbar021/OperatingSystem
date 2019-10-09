#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	pid_t childpid=0;
	int i=0;
if(argc!=2)
{
	printf("Not right argument");
	return 1;

}

int n=atoi(argv[1]);
for(i=1;i<n;i++)
   if((childpid=fork())!=0)
      break;

   fprintf(stderr,"%d process id %d ==> parent id %d & childid %d \n", i, (long)getpid(), (long)getppid(), (long)childpid);

return 0;
}
