#include <stdio.h>

int main() {
    int p = 3, q = 11;

    int n = p * q;
    int e = 7;
    int d = 3;

    int msg;

    printf("Enter message: ");
    scanf("%d", &msg);

    int encrypted = 1;

    for (int i = 0; i < e; i++) {
        encrypted = (encrypted * msg) % n;
    }

    printf("Encrypted = %d\n", encrypted);

    int decrypted = 1;

    for (int i = 0; i < d; i++) {
        decrypted = (decrypted * encrypted) % n;
    }

    printf("Decrypted = %d\n", decrypted);

    return 0;
}