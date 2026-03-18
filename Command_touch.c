#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


// ./touchX    Source.txt  
//  argv[0]    argv[1]     
// argc = 2

/*
    step 1 : Accept file name from command line
    stap 2 : cheak file exist or not
    step 3 : if it is exist return
    step 4 : if it is not then create


*/
int main(int argc , char  *argv[])
{
    if(argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./touchX filename\n");
        return -1;
    }

    if(access(argv[1],F_OK)==0)
    {
        return 0;
    }
    else
    {
        creat(argv[1],0777);
    }
    return 0;
}