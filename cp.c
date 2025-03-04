#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define count 100
int main(int argc, char **argv)
{
    char buff[count]; // buiffer for saving the File Content
    if(argc != 3)
    {
        printf("Error  use the command \n");
        exit(-1);
    }
   int F_file = open(argv[1],O_RDONLY); // openeing the first file 
   //checking for the validaion of the file existing
   if(F_file < 0)
   {
    printf("Error ocuured durring opening the first file \n");
    exit(0);
   }
   int S_file = open(argv[2] ,O_WRONLY | O_CREAT);
   if(S_file < 0)
   {
    printf("Error ocuured durring opening Secound file \n");
    exit(-3);
   }
   int copieditems; //  if true it will return the bytes of the readed file
   while((copieditems = read(F_file , buff , count))  > 0)
   {
    if(write(S_file ,buff ,copieditems) != copieditems)
    {
        printf("Error occred during coping files /n");
        close(F_file);
        close(S_file);
        exit(-4);
    }
   }
   printf("Done Processign ... \n");
   close(F_file);
   close(S_file);
}
