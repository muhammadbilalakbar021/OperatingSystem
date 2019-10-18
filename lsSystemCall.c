#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>

int main(void) 
{ 
    struct dirent *directory; 
    DIR *dir = opendir("."); 
  
    if (dir == NULL)
    { 
        printf("Could not open directory" ); 
        return 0; 
    } 
  
    while ((directory = readdir(dir)) != NULL)
    {
    	printf("Directory Name :%s\n", directory->d_name);
    	printf("INode Number   :%i\n\n",directory->d_ino);
    }

  
    closedir(dir);     
    return 0; 
} 