#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define count 1000

int main(int argc, char **argv) 
{
    char buff[count];

    if (argc != 3) { //checking to user error
        printf("Usagecommand  mv source destination\n");
        exit(1);
    }


    int source = open(argv[1], O_RDONLY); //opening the source file
    if (source < 0) {
        printf("Error opening source file");
        exit(2);
    }
    // open return the FD of the file describtor if true if false returun -1
    int destination = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644); //try to open the destination file if found or create one
    if (destination < 0) {
        printf("Error opening destination file");
        close(source);
        exit(3);
    }

    int bytes;
    //read -  return the bytes if true else return -1
    while ((bytes = read(source, buff, count)) > 0) { //reading the source file and save the bytes read in bytes 
        if (write(destination, buff, bytes) != bytes) {  // write the bytes in the destination file and check if not same false
            printf("Error writing to destination file");
            close(source);
            close(destination);
            exit(4);
        }
    }

    if (bytes < 0)  // readig fault of source file
    {
        printf("Error reading source file");
        exit(-2);
    }

    
    close(source);
    close(destination); 
    // closing the files opened
    if (unlink(argv[1]) < 0) //remove file  as mv command do
    {
        printf("Error deleting source file");
        exit(5);
    }

    return 0;
}
