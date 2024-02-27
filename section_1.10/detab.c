/* Write a program _detab_ that replaces tabs
in the input with the proper number of blanks
to space to the next tab spot. Assume a fixed
set of tab stops, say every 'n' columns. Should
'n' be a variable or a symbolic parameter? */

#include <stdio.h>

#define TAB_STOP_SPACES 4
#define MAX_LINE_LENGTH 1000

int get_line_with_arbitrary_length(char s[], int limit);


int main()
{
    char line[MAX_LINE_LENGTH];

    while(get_line_with_arbitrary_length(line, MAX_LINE_LENGTH) > 0)
    {
        printf("%s", line);
    }

    return 0;
}

/* Read as much of the line into s as is within the limit;
return the length of line even exceeding the limit */
int get_line_with_arbitrary_length(char s[], int limit)
{
    int c, i, end_of_line;

    /* for loop continues past limit to EOF or newline
    i continues to track arbitrary length */
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i < limit - 1)
        {
            s[i] = c;
        }
    }

    /* Best fit needs to include space for '\n' and '\0' */
    if (i > limit - 2)
    {
        end_of_line = limit - 2;
    }
    else
    {
        end_of_line = i;
    }

    if (c == '\n')
    {
        s[end_of_line] = c;
        ++end_of_line;
        /* Increment i so that \n is
        counted as one character */
        ++i;
    }

    s[end_of_line] = '\0';
    return i;
}
