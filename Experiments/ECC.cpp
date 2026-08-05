#include <stdio.h>

int main() {
    int privateKey = 7;

    int Gx = 2;
    int Gy = 5;

    int publicX = privateKey * Gx;
    int publicY = privateKey * Gy;

    printf("Private key = %d\n", privateKey);

    printf("Public key = (%d, %d)\n", publicX, publicY);

    return 0;
}