#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MSGSIZE 23
char* msg = "my name is Bilal Akbar."; 
 
  
int main() 
{ 
    char Sentence_Array[MSGSIZE]; 
    int pipe_[2], nbytes, pid; 
    int child_pid;

    //child_pid=fork();
  
    if (pipe(pipe_) < 0) 
        {
        	perror("Pipe Error");
        	exit(1);
        } 
  
    if ((pid = fork()) > 0) { 
        write(pipe_[1], msg, MSGSIZE);     
        close(pipe_[1]); 
        wait(NULL); 
    } 
    else if(pid == 0)
    {
        close(pipe_[1]); 
        while ((nbytes = read(pipe_[0], Sentence_Array, MSGSIZE)) > 0) 
            printf("%s\n", Sentence_Array); 
        if (nbytes != 0) 
            exit(2); 
        printf("Finished reading\n"); 
    } 
    return 0; 
} 