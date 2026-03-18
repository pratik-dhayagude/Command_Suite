#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>


// ./statX    Source.txt  
//  argv[0]    argv[1]     
// argc = 2

/*
    step 1 : Accept file name from command line
    step 2 : call access to cheak existance the metadata 
    step 3 : call stat system call to get file data 
    stap 4 : Display the meta data 


*/
int main(int argc , char  *argv[])
{
    if(argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./statX filename\n");
        return -1;
    }

    if(access(argv[1],F_OK)==0)
    {
        struct stat sobj;
        int iRet = 0;

        iRet = stat(argv[1],&sobj);

        if(iRet == -1)
        {

            printf("Error : Unable to fetch statical information\n");
            return -1;
        }
        printf("Filename %s\n",argv[1]);
        printf("FileSizee %ld\n",(long)sobj.st_size);
        printf("InodeNumer %ld\n",(long)sobj.st_ino);
        

    }
    else
    {
       printf("Error : File not found\n");
       return -1;

    }

   
    return 0;
}