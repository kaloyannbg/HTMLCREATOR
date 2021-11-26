#include "../main.h"

void printNewLines(int count) {
    for(int i = 0; i < count; i++) {
        printf("\n");
    }
}

string enterChars()
{
    int count = 0;
    char c = 0;
    string dynArr = (string)malloc(MAX_BUFFER);

    while (c != '\n')
    {
        c = getchar();
        if (count > MAX_BUFFER - 1)
        {
            printf("Your text is cutted to %d chars.", MAX_BUFFER);
            break;
        }
        else if (c != '\n')
        {
            dynArr[count++] = c;
        }
        else if (c == '\n')
        {
            dynArr[count] = '\0';
            break;
        }
    }

    return dynArr;
}

void cleanBuffer()
{
    fflush(stdin);
}