#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/utsname.h>

// ./unameX    
//  argv[0]       
//  argc = 1

/*
    step 1:
        call the system call uname
    
    step 2:
        print the result of information form uts name structure
   
*/

int main(int argc , char  *argv[])
{
    struct utsname obj;

    int iRet = 0;

    iRet = uname(&obj);

    if(iRet == -1)
    {
        printf("Error : unable to fetch sysytrm information\n");
        return -1;

    }
    printf("Name of os: %s\n",obj.sysname);
    printf("Name of nodename: %s\n",obj.nodename);
    printf("Name of release: %s\n",obj.release);
    printf("Name of version: %s\n",obj.version);



    return 0;
}