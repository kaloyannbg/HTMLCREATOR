#include "main.h"

int main()
{
    char buffer[MAX_BUFFER] = {0};
    html_t htmlInst;
    system("cls");
    printf(" -- LINKED IN -- ");
    printNewLines(1);
    printf(" -- KALOYAN ANGELOV -- ");
    printNewLines(1);
    printf(" -- HTML CREATOR -- ");
    printNewLines(1);
    printf(" -- Enter your filename (without extension): ");
    scanf("%s", buffer);
    cleanBuffer();
    createNewHTMLFile(buffer, &htmlInst);

    return 0;
}
