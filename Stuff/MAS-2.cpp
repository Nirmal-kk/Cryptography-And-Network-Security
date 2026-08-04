#include<stdio.h>
#include<ctype.h>
#include<string.h>
void MASEncryption(char plain[]){
	char cipher[100];
	key[]="QWERTYUIOPASDFGHJKLZXCVBNM";
	for(i=0;plain[i]!='\0';i++){
		if(isupper(plain[i])){
			cipher[i]=key[plain[i]-'A'];
		}
		else if(islower(plain[i])){
			cipher[i]=islower(key[plain[i]-'a']);
		}
		else{
			cipher[i]=plain[i];
		}
	}
}
void MASDecryption(char cipher[],char plain[]){
	
}
int main(){
	char plain[100];
	char cipher[100];
	printf("Enter The Plain Text:");
	fgets(plain,sizeof(plain),stdin);
	MASEncryption(plain);
}