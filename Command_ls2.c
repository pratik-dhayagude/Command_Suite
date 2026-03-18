#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

// ./lsX     -i   
//  argv[0]  argv[1]
// argc = 2

/*
    step 1 : open the crrent directory (".")
    step 2 : Read all entry from that directory 
    step 3 : Read all the name of file 
    step 4 : close the directory
*/

int main(int argc , char  *argv[])
{
   
   int optation = 0;
   // optation 1 = ls -a
   // optation 2 = ls -i
   
  
   if(argc == 1)
   {
    optation = 1;
   }
   else if(strcmp(argv[1],"-a")==0)
   {
    optation =1;
    
   }
   else if(strcmp(argv[1],"-i")==0)
   {
    optation =2;
   }
   else
   {
    printf("Error : There is no such optation\n");
   }

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
      if(optation==1)
      {
      printf("%s\n",dobj->d_name);
      }
      else if(optation == 2)
      {
        printf("%ld\t%s\n",dobj->d_ino,dobj->d_name);
      }
     
   }

   closedir(dp);
    return 0;
}

