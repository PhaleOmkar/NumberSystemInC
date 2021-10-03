#include <stdio.h>

#define MAX_NUMBER 255
#define MAX_SIZE 8

int main(void)
{
    // Local Function Declaration
    void DecimalToBinary(int inputNumber, int binaryNumberArray[]);
    void DecimalToOctal(int inputNumber, int octalNumber[]);
    void DecimalToHexadecimal(int inputNumber, int hexadecimalNumberArray[]);

    // Local Variable Declaration
    int number;
    int index;
    int binaryNumber[MAX_SIZE] = {0};
    int octalNumber[MAX_SIZE] = {0};
    int hexadecimalNumber[5] = {0};

    // Code
    printf("#################################################\n");
    printf("# Decimal |   Binary  |    Octal  | Hexadecimal #\n");
    printf("#################################################\n");

    for (number = 1; number <= MAX_NUMBER; number++)
    {
        printf("#  %4.3d   | ", number);

        DecimalToBinary(number, binaryNumber);
        for (index = (sizeof(binaryNumber) / sizeof(binaryNumber[0]) - 1); index >= 0; index--)
        {
            printf("%d", binaryNumber[index]);

            if (index % 4 == 0)
            {
                printf(" ");
            }
        }
        printf("| ");

        DecimalToOctal(number, octalNumber);
        for (index = (sizeof(octalNumber) / sizeof(octalNumber[0]) - 1); index >= 0; index--)
        {
            printf("%d", octalNumber[index]);

            if (index % 4 == 0)
            {
                printf(" ");
            }
        }
        printf("| ");

        DecimalToHexadecimal(number, hexadecimalNumber);
        for (index = (sizeof(hexadecimalNumber) / sizeof(hexadecimalNumber[0]) - 1); index >= 0; index--)
        {
            printf("%c", hexadecimalNumber[index]);

            if (index % 4 == 0)
            {
                printf(" ");
            }
        }
        printf("     #\n");

        if (number < MAX_NUMBER)
        {
            printf("#---------+-----------+-----------+-------------#\n");
        }
    }
    printf("#################################################\n");

    return (0);
}

void DecimalToBinary(int inputNumber, int binaryNumberArray[])
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

void DecimalToOctal(int inputNumber, int octalNumber[])
{
    // Local Variable Declaration
    int index;

    // Code
    for (index = 0; inputNumber > 0; index++)
    {
        octalNumber[index] = inputNumber % 8;
        inputNumber = inputNumber / 8;
    }
}

void DecimalToHexadecimal(int inputNumber, int hexadecimalNumberArray[])
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
            temp = temp + 48;
        }
        else
        {
            temp = temp + 55;
        }

        hexadecimalNumberArray[index] = temp;

        inputNumber = inputNumber / 16;
    }
}
