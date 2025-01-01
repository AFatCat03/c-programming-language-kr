#include <stdio.h>

#undef LINE_OK
#define LINE_OK 0
#undef LINE_TOO_LONG
#define LINE_TOO_LONG 1

/* getline: read a line(end with the first target char) from s(start at start index) into t, return length */
int getline(const char *s, char *t, int start, char target, int lim)
{
    int c, i, state;
    state = LINE_OK;
    for (i = 0; state == LINE_OK && (c = *(s + start + i)) != EOF && c != target && c != '\0'; ++i)
    {
        *(t + i) = c;
        if(i == lim - 2)
            state = LINE_TOO_LONG;
    }
    if(c == target)
    {
        *(t + i) = c;
        ++i;
    }
    *(t + i) = '\0';

    if(state == LINE_TOO_LONG)
    {
        while((c = *(s + start + i)) != EOF && c != target && c != '\0')
            ++i;
        if(c == target)
            ++i;
    }
    return i;
}