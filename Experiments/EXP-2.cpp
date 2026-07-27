#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char keyMatrix[SIZE][SIZE];

void generateKeyMatrix(char key[])
{
    int used[26] = {0};
    int i, j = 0, k = 0;

    used['J' - 'A'] = 1;

    for (i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);

        if (ch == 'J')
            ch = 'I';

        if (ch < 'A' || ch > 'Z')
            continue;

        if (!used[ch - 'A'])
        {
            keyMatrix[j][k] = ch;
            used[ch - 'A'] = 1;
            k++;

            if (k == SIZE)
            {
                k = 0;
                j++;
            }
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (!used[i])
        {
            keyMatrix[j][k] = i + 'A';
            k++;

            if (k == SIZE)
            {
                k = 0;
                j++;
            }
        }
    }
}

void findPosition(char ch, int *row, int *col)
{
    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (keyMatrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void playfairEncrypt(char a, char b)
{
    int r1, c1, r2, c2;

    findPosition(a, &r1, &c1);
    findPosition(b, &r2, &c2);

    if (r1 == r2)
    {
        printf("%c%c",
               keyMatrix[r1][(c1 + 1) % SIZE],
               keyMatrix[r2][(c2 + 1) % SIZE]);
    }
    else if (c1 == c2)
    {
        printf("%c%c",
               keyMatrix[(r1 + 1) % SIZE][c1],
               keyMatrix[(r2 + 1) % SIZE][c2]);
    }
    else
    {
        printf("%c%c",
               keyMatrix[r1][c2],
               keyMatrix[r2][c1]);
    }
}

int main()
{
    char key[100], text[100], plain[200];
    int i, j = 0;

    printf("Enter Key: ");
    gets(key);

    printf("Enter Plain Text: ");
    gets(text);

    generateKeyMatrix(key);

    printf("\nKey Matrix:\n");
    for (i = 0; i < SIZE; i++)
    {
        for (int k = 0; k < SIZE; k++)
            printf("%c ", keyMatrix[i][k]);
        printf("\n");
    }

    for (i = 0; text[i] != '\0'; i++)
    {
        char ch = toupper(text[i]);

        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z')
            plain[j++] = ch;
    }
    plain[j] = '\0';

    char finalText[200];
    int len = 0;

    for (i = 0; plain[i] != '\0'; i++)
    {
        finalText[len++] = plain[i];

        if (plain[i + 1] != '\0' && plain[i] == plain[i + 1])
            finalText[len++] = 'X';
    }

    if (len % 2 != 0)
        finalText[len++] = 'X';

    finalText[len] = '\0';

    printf("\nPrepared Text: %s\n", finalText);

    printf("Cipher Text: ");

    for (i = 0; i < len; i += 2)
        playfairEncrypt(finalText[i], finalText[i + 1]);

    printf("\n");

    return 0;
}