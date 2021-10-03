#include <stdio.h>

#define MAX_SIZE 16

int main(void)
{
    // Local Function Declaration
    void BinaryToDecimal(int inputNumber, int binaryNumberArray[]);
    void OctalToDecimal(int inputNumber, int octalNumberArray[]);
    void HexadecimalToDecimal(int inputNumber, int hexadecimalNumberArray[]);

    // Local Variable Declaration
    int number;
    int index;
    int binaryNumber[MAX_SIZE] = {0};
    int octalNumber[MAX_SIZE] = {0};
    int hexadecimalNumber[19] = {0};

    // Code
    printf("================================================\n");
    printf("Enter the number to convert: ");
    scanf("%d", &number);
    printf("================================================\n");

    printf("################################################\n");
    printf("## Decimal       : %19d\n", number);

    BinaryToDecimal(number, binaryNumber);
    printf("## Binary        : ");
    for (index = (sizeof(binaryNumber) / sizeof(binaryNumber[0]) - 1); index >= 0; index--)
    {
        printf("%d", binaryNumber[index]);

        if (index % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");

    OctalToDecimal(number, octalNumber);
    printf("## Octal         : ");
    for (index = (sizeof(octalNumber) / sizeof(octalNumber[0]) - 1); index >= 0; index--)
    {
        printf("%d", octalNumber[index]);

        if (index % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");

    HexadecimalToDecimal(number, hexadecimalNumber);
    printf("## Hexadecimal   : ");
    for (index = (sizeof(hexadecimalNumber) / sizeof(hexadecimalNumber[0]) - 1); index >= 0; index--)
    {
        printf("%c", hexadecimalNumber[index]);
    }
    printf("\n");

    printf("################################################\n");

    return (0);
}

void BinaryToDecimal(int inputNumber, int binaryNumberArray[])
{
    // Local Variable Declaration
    int index;

    // Code
    for (index = 0; inputNumber > 0; index++)
    {
        binaryNumberArray[index] = inputNumber % 2;
        inputNumber = inputNumber / 2;
    }
}

void OctalToDecimal(int inputNumber, int octalNumberArray[])
{
    // Local Variable Declaration
    int index;

    // Code
    for (index = 0; inputNumber > 0; index++)
    {
        octalNumberArray[index] = inputNumber % 8;
        inputNumber = inputNumber / 8;
    }
}

void HexadecimalToDecimal(int inputNumber, int hexadecimalNumberArray[])
{
    // Local Variable Declaration
    int index;
    int temp = 0;

    // Code
    for (index = 0; inputNumber > 0; index++)
    {
        temp = inputNumber % 16;

        if (temp < 10)
        {
            hexadecimalNumberArray[index] = temp + 48;
        }
        else
        {
            hexadecimalNumberArray[index] = temp + 55;
        }

        inputNumber = inputNumber / 16;
    }
}
