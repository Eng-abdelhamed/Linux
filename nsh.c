#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define count 100
int main()
{
char input[count];
printf("Processing nano shell ....\n");
while(1)
{
    printf("NANO >> ");
    if(!fgets(input , count , stdin)) // input
    {
        printf("Error");
        break;
    }
    input[strcspn(input, "\n")] = 0;

    if(strcmp(input,"EXIT") == 0)
    {
        printf("See u soon /n");
        break;
    }
    else if(strncmp(input ,"echo " , 5) == 0)
    {
        printf("%s \n" , input + 5); // printf after echo ;
    }
    else
    {
        printf("Invalid Command \n");
    }
}

}
