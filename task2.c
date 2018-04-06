#include "task2.h"

char   reversalchar(char ch){
	if(!(ch == '1' || ch == '0') ){
		g_print("must be 1 or 0");\
			exit(0);
	}
	if( ch == '1' ){
		return '0' ;
	}
	return '1' ;
}
char * algorithm1(char * string , int wordLength){
	char * result ;
	WordLength = wordLength;
	if(*string == '+'){
		result = HandleOriginalPlus(string+1);
	}
	else{
		result = HandleOriginalNegative(string+1);
	}
	return result ;
}
char * HandleOriginalPlus(char *string){
	char * result ;
	if(!judgePoint(string)){
		result = HandleOriginalPlusInteger(string);
	}
	else{
		result = HandleOriginalPlusDecimal(string);
	}
	return result ;
}
status judgePoint(char * string){
	for(int i = 0 ;i < strlen(string) ; i ++){
		if(string[i] == '.'){
			return OK ;
		}
	}
	return FALSE ;
}
char * HandleOriginalPlusInteger(char *string){
	char * String = (char * )malloc(sizeof(char ) * WordLength);
	int i = 0 ;
	int j = 0 ;
	memset(String, '0', WordLength -1);
	for( i = WordLength - strlen(string) ; i < WordLength; i ++,j ++ ){
		String[i] =  string[j];	
	}
	String[i] = '\0' ;
	return String ;
}
char * HandleOriginalPlusDecimal(char * string){
	char * String = (char *)malloc(sizeof(char) * WordLength + 1);
	int i = 0 ;
	int j = 0 ;
	for( ; i < WordLength + 1 ; i ++ ,j ++){
		if(j < strlen(string)){
			String[i] = string[j] ;
		}
		else{
			String[i] = '0' ;
		}
	}
	String[i] = '\0' ;
	return String;
}
char * HandleOriginalNegative(char *string){
	char * result ;
	if(!judgePoint(string)){
		result = HandleOriginalNegativeInteger(string); 
	}	
	else{
		result = HandleOriginalNegativeDecimal(string);
	}
	return result ;
}
char * HandleOriginalNegativeInteger(char * string){
	char * String = HandleOriginalPlusInteger(string);
	*String = '1' ;
	return String ;
}
char * HandleOriginalNegativeDecimal(char * string){
	char * String = HandleOriginalPlusDecimal(string);
	* String = '1' ;
	return String  ;
}
char * algorithm2(char * string , int wordLength){
	char * originalCode = algorithm1(string, wordLength);
	int flage = 1 ;
	if(*string == '+'){
		return originalCode;
	}
	for(int i = strlen(originalCode) - 1  ; i > 0  ;i-- ){
		if(originalCode[i] == '1' ){
			i -- ;
			while(i > 0 ){
				if(originalCode[i] == '.' ){
					i --     ;
					continue ;
				}
				originalCode[i] = reversalchar(originalCode[i]);
				i -- ;

			}
			break ;
		}
	}
	return originalCode;
}
char * algorithm3(char * string , int wordLength){
	char * originalCode = algorithm1(string , wordLength);	
	if(*string == '+'){
		return originalCode ;
	}
	for (int i = strlen(originalCode) -1 ; i > 0 ; i --){
		if(originalCode[i] == '.' ){
			continue ;
		}
		originalCode[i] =  reversalchar(originalCode[i]);
	}	
	return originalCode;
}
char * algorithm4(char * string , int wordLength){
	char * complement = algorithm2(string, wordLength);
	*complement = reversalchar(*complement);
	return  complement;
}
