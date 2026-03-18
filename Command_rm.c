#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/utsname.h>

// ./rmX      filename
//  argv[0]   argv[1]    
//  argc = 2

/*
    step 1:
        call the system call rm
    
    step 2:
        print the result of information form uts name structure
*/

int main(int argc , char  *argv[])
{

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        printf("Use command as : ./rmX Filename\n");
        return -1;
    }

    int iRet = 0;

    iRet = unlink(argv[1]);

    if(iRet == -1)
    {
        printf("Unable to delete the file\n");
        return -1;
    }
    printf("File gets successfully deleted\n");


    return 0;
}