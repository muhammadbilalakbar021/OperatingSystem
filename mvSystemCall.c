#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    FILE *testPointer,*trainPointer;
    char ch;

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
    fclose(trainPointer);

    if (open("tempfile", O_RDWR) < 0)
        err_sys("open error");
    if (unlink("tempfile") < 0)
        err_sys("unlink error");

    printf("file unlinked\n");
    
    sleep(15);
    exit(0);
    return 0;
}