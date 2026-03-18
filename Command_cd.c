#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


// ./cdX       directorypath  
//  argv[0]    argv[1]     
//  argc = 2

/*
  step1:
    Accept new directory path
  step 2:
    call chdir with that path
  step 3:
    call get cwd to cheak the changed path
*/
int main(int argc , char  *argv[])
{

    if(argc != 2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use command as : ./cdX Directorypath\n");
        return -1;
    }
    if( chdir(argv[1]))
    {
        printf("Error : unable to change the current dirsctory\n");
        return -1;
    }
    char Buffer[250]={'\0'};
    getcwd(Buffer,sizeof(Buffer)-1);
    printf("Current directory changed  to %s\n",Buffer);
    
    return 0;
}