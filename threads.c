#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
int arr[50],n,i;

void *find_Average() 
{ 
  sleep(1); 
  int sum=0;
  float average;
  printf("enter your number :=");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  for(i=0;i<n;i++)
    {
      sum=sum+arr[i];
    }
  average=sum/n;
  printf("The average value is:%f",average);
} 


void *find_Minimum()
{


  int temp=arr[0];
  for(int i=1;i<n;i++)
    {
      if(temp>arr[i])
      {
      temp=arr[i];
      }
    }
  printf("\nThe Minimum  value is:=%d",temp);

}  
void *find_maximum()
{

  int temp=arr[0];
  for(int i=1;i<n;i++)
    {
      if(temp<arr[i])
      {
      temp=arr[i];
      }
    }
  printf("\nThe Maximum  value is:=%d",temp);
}

int main() 
{ 
  pthread_t thread_1,thread_2,thread_3; 
  int x=100;

  printf("Before Thread\n"); 
  if (pthread_create(&thread_1, NULL, &find_Average, NULL)==-1)
  {
    printf("Thread Creation Failed!");
    return 1;
  }
  pthread_join(thread_1,NULL);
  if (pthread_create(&thread_2, NULL, &find_Minimum, NULL)==-1)
  {
    printf("Thread Creation Failed!");
    return 1;
  }
  pthread_join(thread_2,NULL);
  if (pthread_create(&thread_3, NULL, &find_maximum, NULL)==-1)
  {
    printf("Thread Creation Failed!");
    return 1;
  }
  pthread_join(thread_3,NULL); 
  
  
  
  
    printf("After Thread\n"); 
    exit(0); 
}