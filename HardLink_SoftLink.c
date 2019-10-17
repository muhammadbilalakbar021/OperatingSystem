#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int  main(void) {
   pid_t childpid;

   for (int i = 1; i < 7; ++i)
   {
   	//    childpid = fork();
	   // if (childpid == -1)  {
	   //     perror("Failed to fork");
	   //     return 1;
	   //}
	   if ((childpid=fork())!=0) {        
	       if (i==1)
	       {
	       	execl("/usr/bin/touch", "touch","newFile.txt", NULL);
	       	perror("Failed to execute Touch");
	       	printf("New File iis created by Touch \n");
	       }
	       else if (i==2)
	       {
	       	execl("/bin/cat", "cat", "-n","newFile.txt", NULL);
	       	perror("Failed to execute CAT");
	       	printf("Displaying file using Cat \n");
	       }
	       else if (i==3)
	       {
	       	execl("/bin/ln", "ln", "myfile", "link-name", NULL);
	       	perror("Failed to execute LN");	       
	       }
	       else if (i==4)
	       {
	       	execl("/bin/ls", "ls", "-l", NULL);
	       	perror("Child failed to exec LS");	       
	       }
	       else if (i==5)
	       {
	       	execl("/bin/ln", "ln","-s", "myfile","symlink", NULL);
	       	perror("Child failed to exec LN");	      
	       }
	       else if (i==6)
	       {
	       	execl("/bin/ls", "ls", "-l", NULL);
	       	perror("Child failed to exec LS");
	       }
	       
	       return 1;
	   }
	   // if (childpid != wait(NULL)) {                  
	   //     perror("Parent failed to wait due to signal or error");
	   //     return 1;
	   // }
   }
   return 0;
}
