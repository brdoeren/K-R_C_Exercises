/* Write a program to remove trailing blanks
and tabs from each line of input, and to
delete entirely blank lines */

#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int get_line_removing_trailing_whitespace(char line[], int max_line);

int main()
{
    int current_length, i;
    char line[MAX_LINE_LENGTH];

    while((current_length = get_line_removing_trailing_whitespace(line, MAX_LINE_LENGTH)) > 0)
    {
        /* This printing demonstrates that
        the returned line has indeed been
        trimmed of excess whitespace
        via comma-separated values */
        for (i = 0; i < current_length; ++i)
        {
            putchar(line[i]);
            putchar(',');
        }
        putchar('\n');

        printf("%s\n", line);
    }

    return 0;
}

/* get_line_removing_trailing_whitespace: gets a line and copies
it to s, while removing trailing spaces and tabs, returns the
length of the final line; lines only comprised of spaces
and tabs return a length of 0 */
int get_line_removing_trailing_whitespace(char s[], int limit)
{
    int c, i, j, k;

    /* limit - 1 gives room in line[] for the final \n\0 */
    for (i = 0; i < limit - 1  && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    /* At this point, i covers the string up to \n\0 */
    putchar(s[i]);
    putchar('\n');

    k = 0;
    /* Iterate up to current i;
    the final string should be: '...','\n','\0' */
    for (j = 0; j < i; ++j)
    {
        /* Update k to largest non-whitespace index */
        if (s[j] != ' ' && s[j] != '\t')
        {
            k = j;
        }
    }
    /* k is now at last non-whitespace character */

    if (k > 0 && c == '\n')
    {
        ++k;
        s[k] = c;
        ++k;
    }
    s[k] = '\0';

    /* Entirely blank lines are length 0 */
    return k;
}
