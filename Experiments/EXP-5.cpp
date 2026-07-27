#include<stdio.h>
#include<string.h>

int main() {
    char a[100], c[100], d[100];
    int i,j,k,l;

    printf("Enter Plaintext: ");
    scanf("%s",a);

    l=strlen(a);

    for(i=0,j=0;i<l;i+=2)
        c[j++]=a[i];

    for(i=1;i<l;i+=2)
        c[j++]=a[i];

    c[j]='\0';

    printf("Encrypted Text: %s\n",c);

    k=(l+1)/2;

    for(i=0,j=0;i<k;i++,j+=2)
        d[j]=c[i];

    for(i=k,j=1;i<l;i++,j+=2)
        d[j]=c[i];

    d[l]='\0';

    printf("Decrypted Text: %s",d);

    return 0;
}