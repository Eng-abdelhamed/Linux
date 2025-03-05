#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define count 100
int main(int argc , char ** argv)
{
    char buf[count];
    getcwd(buf , count); // this function return the bath to the buffer 

    int writeenbytes = write(1 , buf , count);
    if(writeenbytes < 0)
    {
        printf("Error /n");
        exit(-2);
    }
    write(1 , "\n" , 1); // new line for better readability 
}