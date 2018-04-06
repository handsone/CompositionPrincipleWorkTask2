#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>  

typedef int status ;
#define OK 1 
int WordLength ;

char * algorithm1(char * string , int wordLength);
char * algorithm2(char * string , int wordLength);
char * algorithm3(char * string , int wordLength);
char * algorithm4(char * string , int wordLength);
char * HandleOriginalPlus(char *string);
char * HandleOriginalPlusInteger(char *string );
char * HandleOriginalPlusDecimal(char *string);
char * HandleOriginalNegative(char *string);
char * HandleOriginalNegativeDecimal(char *string);
char * HandleOriginalNegativeInteger(char *string);
char   reversalchar(char ch);
status judgePoint(char * string);
