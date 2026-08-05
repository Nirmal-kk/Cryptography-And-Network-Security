#include <stdio.h>
#include <string.h>

int main() {
    char text[100], key;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter a character key: ");
    scanf(" %c", &key);

    for (int i = 0; i < strlen(text); i++) {
        text[i] ^= key;
    }

    printf("Encrypted text: %s\n", text);

    for (int i = 0; i < strlen(text); i++) {
        text[i] ^= key;
    }

    printf("Decrypted text: %s\n", text);

    return 0;
}