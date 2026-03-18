#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define MAX_BUFFER_SIZE 1024

// ./catX    Source.txt  
//  argv[0]    argv[1]     
// argc = 2

/*
    step 1 : Accept file name from command line
    stap 2 : cheak file exist or not
    step 3 : if it is exist return
    step 4 : print on console
    


*/
int main(int argc , char  *argv[])
{
    if(argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./catX filename\n");
        return -1;
    }

    if(access(argv[1],F_OK)!=0)
    {
        printf("cat: %s: No such file or directory\n",argv[1]);
        return -1;
    }
    else
    {
        int fd = 0;
        fd = open(argv[1],O_RDONLY);
        if(fd < 0)
        {
            printf("Error : unable to open they file\n");
            return -1;
        }
        char * Buffer[MAX_BUFFER_SIZE];

        int iRet = 0;

        while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
        {
            write(1,Buffer,iRet);
        }

        printf("\n");

        close(fd);

    }


    return 0;
}