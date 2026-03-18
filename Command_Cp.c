#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define MAX_BUFFER_SIZE 1024

// ./cpX    Source.txt  dest.txt
//  argv[0] argv[1]     argv[2]
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
        printf("Use command as : ./cpX Sourcefilename Destinationfiename\n");
        return -1;
    }

    int fdSrc = 0,fdDest = 0,iRet = 0;

    char Buffer[MAX_BUFFER_SIZE];

    memset(Buffer,'\0',sizeof(Buffer));


    fdSrc = open(argv[1],O_RDONLY);
    if(fdSrc < 0)
    {
        printf("Error : Unable to open source file:%s\n",argv[1]);
        return -1;
    }
    
    fdDest = creat(argv[2],0777);

    if(fdSrc < 0)
    {
        printf("Error : Unable to creat destination file:%s\n",argv[2]);
        close(fdSrc);
        return -1;
    }

    while((iRet = read(fdSrc,Buffer,sizeof(Buffer))) != 0)
    {
        write(fdDest,Buffer,iRet);
        memset(Buffer,'\0',sizeof(Buffer));

    }
    printf("Sucess : copy activity done\n");
    close(fdSrc);
    close(fdDest);

    

    return 0;
}