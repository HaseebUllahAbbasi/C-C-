#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	system( "ps -el | cat >active_processes_using_code.txt");
}