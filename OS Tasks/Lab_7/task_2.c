#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
  int file_desc = open("tricky.txt",O_WRONLY | O_APPEND);
  // here the newfd is the file descriptor of stdout (i.e. 1)
  if(file_desc < 0)
		printf("Error opening the file\n");
  dup2(file_desc, 1) ;
  // All the printf statements will be written in the file
  // "tricky.txt"
  printf("I will be printed in the file tricky.txt\n");
  printf("this is new added line \n");
  return 0;
}
