#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plain[100], cipher[100];
    int key, i;
    printf("Enter plaintext: ");
    scanf("%s", plain);
    printf("Enter key: ");
    scanf("%d", &key);
    for(i = 0; i < strlen(plain); i++) {
        cipher[i] = plain[i] + key;
        if(isupper(plain[i]) && cipher[i] > 'Z')
            cipher[i] -= 26;
        if(islower(plain[i]) && cipher[i] > 'z')
            cipher[i] -= 26;
    }
    cipher[i] = '\0';
    printf("Encrypted Text: %s\n", cipher);
    for(i = 0; i < strlen(cipher); i++) {
        plain[i] = cipher[i] - key;

        if(isupper(cipher[i]) && plain[i] < 'A')
            plain[i] += 26;

        if(islower(cipher[i]) && plain[i] < 'a')
            plain[i] += 26;
    }
    plain[i] = '\0';
    printf("Decrypted Text: %s\n", plain);
    return 0;
}