#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t childpid;
	childpid=fork();

	if(childpid == -1)
	{
		perror("Failed to fork");
		return 1;
	}

	if(childpid == 0)
	{
		execl("/usr/bin/xdg-open","xdg-open","multiProcess.c",NULL);
		perror("Executing URL");
		return 1;
	}

	if(childpid !=0)
	{
		execl("/usr/bin/xdg-open","xdg-open","https://www.google.com",NULL);
		perror("Executing File");
		return 1;
	}

	if(childpid != wait(NULL))
	{
		perror("Parent failed to wait for child to termiante due to signal erroe");
		return 1;
	}

return 0;
}