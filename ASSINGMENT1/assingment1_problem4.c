#include <stdio.h>
#include <stdlib.h>
int freq[1000];
void freq_calculator( )
{
   FILE *fp ;
   int total = 0;
   for(int i = 0;i<1000;i++){
   	freq[i] = 0;
   }
   char c ;
   printf( "Opening the file test.txt in read mode\n" ) ;
   fp = fopen ( "test.txt", "r" ) ; // opening an existing file
   if ( fp == NULL )
   {
     printf ( "Could not open file test.txt\n" ) ;
     exit(1);
   }
   printf( "Reading the file test.c\n'" ) ;
   while ( 1 )
   {
     c = fgetc ( fp ) ; // reading the file
     if ( c == EOF )
     break ;
   	int test = (int)c;
   	freq[test]++;
   	total++;
   }
   printf("test\n");
   printf("Closing the file test.c\n") ;
   printf("There are total %d characters in the file including spaces\n",total );
   fclose ( fp ) ; 
   printf("Enter the character which's frequecncy you wanted to know: ");
   char ch;
   
   scanf("%c",&ch);
   printf("%c has ocuuered %d times in the text file out of %d total characters.\n",ch,freq[(int)ch],total );
}
int main(){
	freq_calculator();
	return 0;

}
/* output:
Opening the file test.txt in read mode
Reading the file test.c
'test
Closing the file test.c
There are total 291 characters in the file including spaces
Enter the character which's frequecncy you wanted to know: p
p has ocuuered 4 times in the text file out of 291 total characters.

*/