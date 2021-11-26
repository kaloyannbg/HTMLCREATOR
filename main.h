#ifndef MAIN_GUARD
#define MAIN_GUARD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/defineFile.h"
#include "headers/structFile.h"

FILE *fp;

string enterChars();
void cleanBuffer();
void printNewLines(int count);

void createNewHTMLFile(string fileName, html_t *html);


#endif // !MAIN_GUARD
