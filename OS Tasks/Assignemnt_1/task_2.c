#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>
double avg;
int mode;
void change_permissions(char const filename[]);
void file_stat(char const filename[]);
void file_permissions(char const filename[]);
void get_result(char const filename[]);
char* number_to_string(double num);
int main(){
  ssize_t read;
  char* filename = 0;
  char* arg = 0;

  size_t buf_size = 0;

  printf("Enter the name of a file to check: \n");
  read = getline(&filename, &buf_size, stdin);

  printf("%s\n",filename);
  if (read <=0 ){
    printf("getline failed\n");
    exit(1);
  }
  if (filename[read-1] == '\n'){
    filename[read-1] = 0;
  }

  int s=open(filename,O_RDONLY);
  if(s==-1){
    printf("File doesn't exist\n");
    exit(1);
  }
  else
  {
    printf("please Enter the second agument \n" );
    read = getline(&arg, &buf_size, stdin);
    if (arg[read-1] == '\n'){
      arg[read-1] = 0;
    }
    char *file_stat_var = "file_stats";
    char *num_stats_var ="num_stats";
     char *change_stats_var = "change_stats";
    if(strcmp(file_stat_var,arg)==0)
      file_stat(filename);
    else if(strcmp(num_stats_var,arg)==0)
      get_result(filename);
    else if(strcmp(change_stats_var,arg)==0)
      change_permissions(filename);
  }
  free(filename);

}
void get_result(char const filename[])
{
  FILE *fptr;
  if ((fptr = fopen("txt.txt","r")) == NULL)
  {
       printf("Error! opening file");
       exit(1);
   }
   int num;
   int array[8];
   int length=0;
   while (fscanf(fptr,"%d", &num)!=-1) {
       array[length] = num;
     length++;
   };

   /*
   Average code
   */
   int sum = 0;
   int maxValue = 0, maxCount = 0, i, j;

   for (i = 0; i < length; ++i)
   {
      int count = 0;
      sum+=array[i];

      for (j = 0; j < length; ++j) {
         if (array[j] == array[i])
         ++count;
      }

      if (count > maxCount) {
         maxCount = count;
         maxValue = array[i];
      }
   }
   mode = maxValue;
   avg = (sum)/(double)(length);
   printf(" the sum is %lf and the mode is %d\n",avg,mode);
   int p[2], pid,nbytes;
    char inbuf[10];
    char array_avg[10];
    char array_mode[10];
  if ((pid = fork()) > 0)
  {
    sprintf(array_avg, "%f", avg);
    sprintf(array_mode, "%d", mode);

    write(p[1], array_avg,10);
    write(p[1], array_mode,10);

  }
  else
  {
    while ((nbytes = read(p[0], inbuf, 10)) > 0)
    printf("%s\n", inbuf);
    printf("Finished reading\n");
  }

}
void file_stat(char const filename[])
{
  struct stat sfile;

  if(stat(filename,&sfile)==-1){
    printf("Error Occurred\n");
  }

  //Accessing data members of stat struct
  printf("\nFile size : %ld \n",sfile.st_size);
  file_permissions(filename);
}
void file_permissions(char const filename[])
{
    struct stat sfile;
    if(stat(filename,&sfile)==-1){
      printf("Error Occurred\n");
    }
  printf("File Permissions User : ");
  printf((sfile.st_mode & S_IRUSR)? "r":"-");
  printf((sfile.st_mode & S_IWUSR)? "w":"-");
  printf((sfile.st_mode & S_IXUSR)? "x":"-");
  printf(" ");
  //printf("\nFile Permissions Group\n");
  printf((sfile.st_mode & S_IRGRP)? "r":"-");
  printf((sfile.st_mode & S_IWGRP)? "w":"-");
  printf((sfile.st_mode & S_IXGRP)? "x":"-");
  printf(" ");
  //printf("\nFile Permissions Other\n");
  printf((sfile.st_mode & S_IROTH)? "r":"-");
  printf((sfile.st_mode & S_IWOTH)? "w":"-");
  printf((sfile.st_mode & S_IXOTH)? "x":"-");
  printf("\n");
}
void change_permissions(char const filename[])
{
  char command[40] = "chmod go-xw ";
  strcat(command, filename);
  system(command);
  file_stat(filename);
}
