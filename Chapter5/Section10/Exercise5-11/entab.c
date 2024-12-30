#include <stdio.h>
#define TAB_STOP 8
/* replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. */
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
            while((c = *(*argv)++) != (EOF) && c != '\0') {
                if(c == ' ')
                {
                    int nb;

                    nb = 0;
                    do
                    {
                        ++col;
                        ++nb;
                        if(col >= TAB_STOP)
                        {
                            putchar('\t');
                            nb = col = 0;
                        }
                    }
                    while((c = *(*argv)++) != EOF && c == ' ');
                    while(nb-- > 0)
                        putchar(' ');
                }
                if(c == EOF)/* handle cases where ' ' is followed by EOF */
                    break;
                putchar(c);
                if(c == '\t' || c == '\n')
                    col = 0;
                else
                    col = (col + 1) & 7;/* limit col between 0 ~ 7(inclusive) */
            }
        }     
    return 0;
}