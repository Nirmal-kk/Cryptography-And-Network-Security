#include <stdio.h>

int power(int base, int exp, int mod) {
    int result = 1;

    while (exp > 0) {
        result = (result * base) % mod;
        exp--;
    }

    return result;
}

int main() {
    int p = 23;
    int g = 5;

    int a = 6;
    int b = 15;

    int A = power(g, a, p);
    int B = power(g, b, p);

    int key1 = power(B, a, p);
    int key2 = power(A, b, p);

    printf("Alice key = %d\n", key1);
    printf("Bob key = %d\n", key2);

    return 0;
}