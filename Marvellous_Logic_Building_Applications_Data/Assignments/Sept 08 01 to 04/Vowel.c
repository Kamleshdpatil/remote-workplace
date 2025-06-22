#include<stdio.h>
#include<stdbool.h>

//typedef int _______ ;

#define TRUE 1
#define FALSE 0

int ChkVowel(char);
int ChkVowel(char Calpha){
	
	if(Calpha >='A' && Calpha <='Z')
	{	
		Calpha=Calpha+32;
		//printf("%c",Calpha);
	}
	if(Calpha == 'a' || Calpha =='e' || Calpha =='i' || Calpha == 'o' ||Calpha == 'u')
		return TRUE;
	else
		return FALSE;
}

int main(){
	char cValue='\0';
	bool bRet = FALSE;
	printf("Enter Character: ");
	scanf("%s", &cValue);
	
	bRet=ChkVowel(cValue);
	if(bRet==TRUE)
		printf("%c is Vowel\n",cValue);
	else
		printf("%c is not vowel\n",cValue);
	
	return 0;
}