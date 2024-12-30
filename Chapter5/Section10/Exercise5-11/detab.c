#include <stdio.h>
#define TAB_STOP 8
/* replaces tabs in the input with the proper number of blanks to space to the next tab stop. */
int main(int argc, char *argv[])
{
    char c;
    int col;
    
    if (argc < 2) 
        printf("Error: Invalid agruments number\n");
    else 
        while(--argc > 0) {
            ++argv;
            col = 0;
            while((c = *(*argv)++) != (EOF) && c != '\0')
                if(c == '\t') {
                    while(col++ < TAB_STOP)
                        putchar(' ');
                    col = 0;
                }
                else {
                    putchar(c);
                    if(c == '\n')
                        col = 0;
                    else
                        col = (col + 1) & 7;/* limit col between 0 ~ 7(inclusive) */
                }
        }
    return 0;
}