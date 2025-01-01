#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1000 
/* tail -n: prints the last n lines of its input. By default, n is set to 10 */
int main(int argc, char *argv[])
{
    char c;
    int tail = 10;
    if(--argc > 0 && **++argv == '-') {
        char *input = *argv;
        int num, flag;
        num = flag = 0;
        while((c = *++input) != (EOF) && c != '\0') {
            if(c < '0' || c > '9') {
                flag = -1;
                break;
            }
            num = num * 10 + c - '0';
        }
        if(num < 0) {
            printf("optional arguments is invalid\n");
            return -1;
        } 
        if(flag == -1)
            ++argc;
        else {
            tail = num;
            --argc, ++argv;
        }
    }

    if(argc != 1) {
        printf("Invalid input\n");
        return -1;
    }
    int getline(const char *s, char *t, int start, char target, int lim), len, index, start;
    char **strs = (char**)malloc(sizeof(char*) * tail), *my_strncpy(char *s, const char *ct, int n), line[MAXLEN];
    if(strs == NULL) {
        printf("Not enough memory\n");
        return -1;
    }
    index = start = 0;
    for(int i = 0; i < tail; ++i) //set all pointers in strs point to NULL
        *(strs + i) = NULL;
    while ((len = getline(*argv, line, start, '\n', MAXLEN)) > 0) {
        start += len;
        *(strs + index) = (char*)malloc(sizeof(char) * len);
        if(*(strs + index) == NULL) {
            printf("Not enough memory\n");
            return -1;
        }
        my_strncpy(*(strs + index), line, len);
        index = (index + 1) % tail;
    }
    for(int i = 0; i < tail; ++i) {
        if(*(strs + index) != NULL)
            printf("%s", *(strs + index));
        index = (index + 1) % tail;
    }
    return 0;
}
