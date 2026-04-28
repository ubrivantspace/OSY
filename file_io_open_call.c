#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fptr;

    fptr = fopen("text4.txt","w");
    fputs("This is the initial line of the file.\n\n", fptr);
    fclose(fptr);

    fptr = fopen("text4.txt","r");
    int ch;
    while ((ch = fgetc(fptr)) != EOF) {
        printf("%c", ch);
    }
    fclose(fptr);

    fptr = fopen("text4.txt","a");
    fputs("This line has been appended to the file.",fptr);
    fclose(fptr);

    fptr = fopen("text4.txt","r");
    while ((ch = fgetc(fptr)) != EOF) {
        printf("%c",ch);
    }
    fclose(fptr);
}
