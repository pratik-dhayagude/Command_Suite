#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


// ./pwdX    
//  argv[0]       
//  argc = 1

/*
    step 1:
        call the system call getcwd
    
    step 2:
        print the result of getcwd
   
*/

int main(int argc , char  *argv[])
{
    char Buffer[1024]={'\0'};

    getcwd(Buffer,sizeof(Buffer));

    printf("%s\n",Buffer);

    return 0;
}