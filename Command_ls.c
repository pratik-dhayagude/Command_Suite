#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

// ./lsX    
//  argv[0]
// argc = 1

/*
    step 1 : open the crrent directory (".")
    step 2 : Read all entry from that directory 
    step 3 : Read all the name of file 
    step 4 : close the directory
*/

int main(int argc , char  *argv[])
{

   char * path = ".";
   DIR * dp = NULL;

   dp = opendir(path);
   if(dp == NULL)
   {
        printf("Error : unable to open the directory\n");
        return -1;
   }

   struct dirent * dobj;

   while((dobj = readdir(dp))!= NULL)
   {
     printf("%s\t",dobj->d_name);
     printf("%d\t",dobj->d_ino);
   }

   closedir(dp);

   
    

    return 0;
}