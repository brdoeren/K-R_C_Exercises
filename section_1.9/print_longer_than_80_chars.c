/* Write a program to print all input lines
that are longer than 80 characters */

#include <stdio.h>

#define MAX_LINE_LENGTH 1000
#define MIN_LENGTH_LINE 80

int get_line_with_arbitrary_length(char s[], int limit);

int main()
{
    int current_length;
    char line[MAX_LINE_LENGTH];

    while((current_length = get_line_with_arbitrary_length(line, MAX_LINE_LENGTH)) > 0)
    {
        if (current_length > MIN_LENGTH_LINE)
        {
            printf("%s", line);
        }
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
