#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    FILE *testPointer,*trainPointer;
    char ch;
    pid_t childpid;
    childpid=fork();

    if (childpid<=0) {        
	 execl("/bin/cat", "cat ",">","testFIle.txt", NULL);
	 perror("Failed to execute cat");
	 printf("New File iis created by cat \n");
	}

    testPointer = fopen("testFIle.txt", "r");
    trainPointer = fopen("trainFIle.txt", "w");
    if (testPointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(testPointer)) != EOF)
        {
            printf("%c", ch);
            fprintf(trainPointer,"%c",ch);
        }
    }
    fclose(testPointer);

    if (unlink("testFIle.txt") < 0)
        printf("unlink error");
    else
	printf("Unlinking Done");

    
    sleep(15);
    exit(0);
    return 0;
}
