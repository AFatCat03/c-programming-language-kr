#include <stdio.h>
#define TAB_STOP 8
/* replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. */
int main(int argc, char *argv[])
{
    if (argc < 2) 
        printf("Error: Invalid agruments number\n");
    else {
        char c;
        int col, start, flag, tab_stop;
        ++argv;
        tab_stop = TAB_STOP;
        start = flag = 0; /* flag: 0 represents no optional arguments, 1 represents '-', 2 represents '+', 3 represents there is no more optional arguments
                             start: The starting index for detabbing operations (zero-based).*/
        while (flag != 3 && --argc > 0 && ((c = **argv) == '-' || c == '+')) {
            char sign = c;
            if(sign == '-')
                flag |= 1;
            else
                flag |= 2;
            int num = 0;
            char *input = *argv;
            while((c = *++input) != (EOF) && c != '\0') {
                if(c < '0' || c > '9') {
                    flag = 0;
                    break;
                }
                num = num * 10 + c - '0';
            }
            if(flag == 0) 
                break;
            if(num < 0) {
                printf("optional arguments is invalid\n");
                return -1;
            }
            if(sign == '-') 
                start = num;
            else if(sign == '+')
                tab_stop = num;
            ++argv;
        }
        if(flag != 3)
            ++argc;
        ++start;

        while(--argc > 0) {
            col = 0;
            while((c = *(*argv)++) != (EOF) && c != '\0') {
                if(start > 0)
                    --start;
                if(c == ' ') {
                    ++start;
                    int nb = 0;
                    do {
                        if(start > 0)
                            --start;
                        ++col;
                        ++nb;
                        if(col >= tab_stop)
                        {
                            if(start == 0)
                                putchar('\t');
                            else
                                while(nb-- > 0)
                                    putchar(' ');
                            nb = col = 0;
                        }
                    } while((c = *(*argv)++) != EOF && c == ' ');
                    while(nb-- > 0)
                        putchar(' ');
                }
                if(c == EOF)/* handle cases where ' ' is followed by EOF */
                    break;
                putchar(c);
                if(c == '\t' || c == '\n')
                    col = 0;
                else
                    col = (col + 1) & (tab_stop - 1);/* limit col between 0 ~ 7(inclusive) */
            }
            ++argv;
        }
    } 
    return 0;
}