#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    char k1, k2, k3;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter three keys: ");
    scanf(" %c %c %c", &k1, &k2, &k3);

    for (int i = 0; i < strlen(text); i++) {
        text[i] ^= k1;
        text[i] ^= k2;
        text[i] ^= k3;
    }

    printf("Encrypted: %s\n", text);

    for (int i = 0; i < strlen(text); i++) {
        text[i] ^= k3;
        text[i] ^= k2;
        text[i] ^= k1;
    }

    printf("Decrypted: %s\n", text);

    return 0;
}