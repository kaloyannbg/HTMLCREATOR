#include "../main.h"

int isFileExist(string fileName)
{
    fp = fopen(fileName, READ_FILE);
    if (fp)
    {
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}

void createNewHTMLFile(string fileName, html_t *html)
{

    char someArray[128];
    sprintf(someArray, "%s/%s.%s", PATH_OF_HTML_FILES, fileName, "html");
    printf(" -- Your Path: %s -- ", someArray);
    printNewLines(1);

    if (isFileExist(someArray))
    {
        printf(" -- File is already exist.");
        return;
    }

    fp = fopen(someArray, WRITE_ROWS_FILE);
    if (fp == NULL)
    {
        printf("\nPROBLEM\n");
        return;
    }
    char buffer[2048] = {0};
    char c = 0;
    strcpy(html->HTML_OPEN, "<html>");
    fprintf(fp, "%s\n", html->HTML_OPEN);

    strcpy(html->HEAD_OPEN, "<head>");
    fprintf(fp, "%s\n", html->HEAD_OPEN);

    printf(" -- Do you want to add style? [y/n]: ");
    cleanBuffer();
    scanf("%c", &c);
    cleanBuffer();

    if (c == 'y' || c == 'Y')
    {
        strcpy(html->STYLE_OPEN, "<style>");
        fprintf(fp, "%s\n body {\n", html->STYLE_OPEN);
        printf(" -- Please enter background color: ");
        scanf("%s", buffer);
        cleanBuffer();
        strcpy(html->BACKGROUND_COLOR, buffer);
        fprintf(fp, "\t\tbackground-color: %s;\n", html->BACKGROUND_COLOR);

        printf(" -- Please enter text color: ");
        scanf("%s", buffer);
        cleanBuffer();
        strcpy(html->TEXT_COLOR, buffer);
        fprintf(fp, "\t\tcolor: %s;\n", html->TEXT_COLOR);

        strcpy(html->STYLE_CLOSE, "} \n</style>\n");
        fprintf(fp, "%s", html->STYLE_CLOSE);
    }

    strcpy(html->TITLE_OPEN, "<title>");
    printf(" -- Please enter your title: ");
    html->TITLE_CONT = enterChars();

    strcpy(html->TITLE_CLOSE, "</title>");
    strcpy(html->HEAD_CLOSE, "</head>");
    strcpy(html->BODY_OPEN, "<body>");
    strcpy(html->BODY_H1_OPEN, "<h1>");
    printf(" -- Please enter your BODY H1 (H1 TITLE): ");
    html->BODY_H1_CONT = enterChars();
    strcpy(html->BODY_H1_CLOSE, "</h1>");
    strcpy(html->BODY_P_OPEN, "<p>");
    printf(" -- Please enter your text: ");
    html->BODY_P_CONT = enterChars();
    strcpy(html->BODY_P_CLOSE, "</p>");
    strcpy(html->BODY_CLOSE, "</body>");
    strcpy(html->HTML_CLOSE, "</html>");

    fprintf(fp, "\t%s\n", html->TITLE_OPEN);
    fprintf(fp, "\t\t%s\n", html->TITLE_CONT);
    fprintf(fp, "\t%s\n", html->TITLE_CLOSE);
    fprintf(fp, "%s\n", html->HEAD_CLOSE);
    fprintf(fp, "%s\n", html->BODY_OPEN);
    fprintf(fp, "\t%s\n", html->BODY_H1_OPEN);
    fprintf(fp, "\t\t%s\n", html->BODY_H1_CONT);
    fprintf(fp, "\t%s\n", html->BODY_H1_CLOSE);
    fprintf(fp, "\t%s\n", html->BODY_P_OPEN);
    fprintf(fp, "\t\t%s\n", html->BODY_P_CONT);
    fprintf(fp, "\t%s\n", html->BODY_P_CLOSE);
    fprintf(fp, "%s\n", html->BODY_CLOSE);
    fprintf(fp, "%s\n", html->HTML_CLOSE);

    fclose(fp);
    printf("Sucesfully created HTML file.");
}