#include <cstdlib>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>


using namespace std;

int main(int argc, char *argv[])
{
    
    FILE *fs1, *fs2, *ft;
 
   char ch, file1[32], file2[32], file3[32], file4[32];
   int cnt=1;
 

    DIR *mydir = opendir("input/");

    struct dirent *entry = NULL;
    
    (entry = readdir(mydir));
    (entry = readdir(mydir));
    (entry = readdir(mydir));
    printf("%s\n", entry->d_name);
    strcpy (file1,"input/");
    strcat (file1,entry->d_name);
    fs1 = fopen(file1,"r");
     if( fs1 == NULL)
   {
      perror("Error ");
      printf("Press any key to exit...\n");
      getch();
      exit(EXIT_FAILURE);
   }
   
   ft = fopen("output/contacts.txt","w");
 
   if( ft == NULL )
   {
      perror("Error ");
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }

     while( ( ch = fgetc(fs1) ) != EOF )
      fputc(ch,ft);   

    
    while((entry = readdir(mydir))) /* If we get EOF, the expression is 0 and
                                     * the loop stops. */
    {
        printf("%s\n", entry->d_name);
        strcpy (file2,"input/");
        strcat (file2,entry->d_name);
        fs2 = fopen(file2,"r");
        
         if(fs2 == NULL )
   {
      perror("Error ");
      printf("Press any key to exit...\n");
      getch();
      exit(EXIT_FAILURE);
   }
        
            fputs("\n\n",ft);
 
 
   while( ( ch = fgetc(fs2) ) != EOF )
      fputc(ch,ft);
   cnt++;
    }

    closedir(mydir);
    
    
 
//   printf("Enter name of first file ");
//   gets(file4);
 
//   strcpy (file1,"input/");
//   strcat (file1,file4);
 
//   printf("Enter name of second file ");
//   gets(file4);
   
//   strcpy (file2,"input/");
//   strcat (file2,file4) ;
 
//   printf("Enter name of file which will store contents of two files ");
//   gets(file4);
   
//   strcpy (file3,"output/");
//   strcat (file3,file4);
   
  
 
//   fs1 = fopen(file1,"r");
//   fs2 = fopen(file2,"r");
 
//   if( fs1 == NULL || fs2 == NULL )
//   {
//      perror("Error ");
//      printf("Press any key to exit...\n");
//      getch();
//      exit(EXIT_FAILURE);
//   }
 
//   ft = fopen("output/contacts.txt","w");
 
//   if( ft == NULL )
//   {
//      perror("Error ");
   //   printf("Press any key to exit...\n");
 //     exit(EXIT_FAILURE);
 //  }
 
 //  while( ( ch = fgetc(fs1) ) != EOF )
 //     fputc(ch,ft);
      
 //     fputs("\n\n",ft);
 
 
//   while( ( ch = fgetc(fs2) ) != EOF )
//      fputc(ch,ft);
 
   printf("%d files were merged into output/contacts.txt file successfully.\n",cnt);
 
   fclose(fs1);
   fclose(fs2);
   fclose(ft);
   
    system("PAUSE");
    return EXIT_SUCCESS;
}
