#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    char k1, k2;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter key 1: ");
    scanf(" %c", &k1);

    printf("Enter key 2: ");
    scanf(" %c", &k2);

    for (int i = 0; i < strlen(text); i++) {
        text[i] ^= k1;
        text[i] ^= k2;
    }

    printf("Encrypted: %s\n", text);

    for (int i = 0; i < strlen(text); i++) {
        text[i] ^= k2;
        text[i] ^= k1;
    }

    printf("Decrypted: %s\n", text);

    return 0;
}