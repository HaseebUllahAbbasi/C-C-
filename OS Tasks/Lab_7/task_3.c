#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
  int res = mkfifo("my_fifo", 0777);
  if (res == 0)
  printf("FIFO created\n");
  exit(EXIT_SUCCESS);
}
