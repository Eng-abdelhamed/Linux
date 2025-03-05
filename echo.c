#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define count 50
int main(int argc , char ** argv)
{
int i = 1;
 while(argv[i]!=NULL)
 {
	 write(1 , argv[i], strlen(argv[i]));
	 i++;
 }
return 0;

}
