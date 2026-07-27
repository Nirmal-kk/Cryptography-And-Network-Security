#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char text[100], key[100];
    int i,j;

    printf("Enter Plaintext: ");
    scanf("%s",text);

    printf("Enter Key: ");
    scanf("%s",key);

    printf("Encrypted Text: ");

    for(i=0,j=0;i<strlen(text);i++,j++){
        if(j==strlen(key))
            j=0;

        printf("%c",65+(((toupper(text[i])-65)+(toupper(key[j])-65))%26));
    }

    return 0;
}