#include<stdio.h>
#include<ctype.h>
#include<string.h>
void encrpytCaesar(char *text,int shift){
	shift=(shift%26+26)%26;
	while(*text!='\0'){
		if(isupper(*text)){
			*text=((*text-'A'+shift)%26)+'A';
		}
		else if(islower(*text)){
			*text=((*text-'a'+shift)%26)+'a';
		}
		text++;
	}
	return 0;
}
void decrpytCaesar(char *text,int shift){
	shift=(26-(shift%26))%26;
	while(*text!='\0'){
		if(isupper(*text)){
			*text=((*text-'A'+shift)%26)+'A';
		}
		else if(islower(*text)){
			*text=((*text-'a'+shift)%26)+'a';
		}
		text++;
	}
}
int main(){
	char message[100];
	char original[100];
	char cipher[100];
	int shift;
	fgets(message,sizeof(message),stdin);
	strcpy(original,message);
	scanf("%d",&shift);
	encrpytCaesar(message,shift);
	strcpy(cipher,message);
	decrpytCaesar(cipher,shift);
	printf("Original Message: %s",original);
	printf("Encrypted Message: %s",message);
	printf("Decrypted Message: %s",cipher);
	return 0;
}