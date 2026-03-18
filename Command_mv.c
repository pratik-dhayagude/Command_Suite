#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


// ./cpX    Sourcepath  destpath
// argv[0]  argv[1]     argv[2]
// argc = 3

/*
    step 1 : open source file for reading
    step 2 : Create destination file
    step 3 : Read the data from source 
    step 4 : Write it into destination

*/
int main(int argc , char  *argv[])
{
    if(argc != 3)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./mvX Sourcepath Destinationpath\n");
        return -1;
    }

    if(rename(argv[1],argv[2])==-1)
    {
        printf("Error : unable to move\n");
        return -1;
    }

    return 0;
}