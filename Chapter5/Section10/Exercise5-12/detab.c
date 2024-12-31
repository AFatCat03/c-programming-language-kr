#include <stdio.h>
#define TAB_STOP 8
/* replaces tabs in the input with the proper number of blanks to space to the next tab stop. */
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
                if(c == '\t') {
                    if(start == 0) 
                        while(col++ < tab_stop)
                            putchar(' ');  
                    else
                        putchar('\t');
                    col = 0;
                }
                else {
                    putchar(c);
                    if(c == '\n')
                        col = 0;
                    else
                        col = (col + 1) & (tab_stop - 1);/* limit col between 0 ~ tab_stop - 1(inclusive) */
                }
            }     
            ++argv;
        }
    }
    return 0;
}