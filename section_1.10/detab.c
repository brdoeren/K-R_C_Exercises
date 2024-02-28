/* Write a program _detab_ that replaces tabs
in the input with the proper number of blanks
to space to the next tab spot. Assume a fixed
set of tab stops, say every 'n' columns. Should
'n' be a variable or a symbolic parameter? */

#include <stdio.h>

#define TAB_STOP_SPACES 4
#define MAX_LINE_LENGTH 1000

int get_line_with_arbitrary_length(char s[], int limit);
void convert_tabs_to_spaces(char source[], char result[], int tab_stop_spaces);

int main()
{
    char line[MAX_LINE_LENGTH];
    char converted_line[MAX_LINE_LENGTH];

    while(get_line_with_arbitrary_length(line, MAX_LINE_LENGTH) > 0)
    {
        convert_tabs_to_spaces(line, converted_line, TAB_STOP_SPACES);
        printf("%s", converted_line);
    }

    return 0;
}

/* Takes string s and converts the tabs in s into spaces
and stores the result in r, tab_stop_spaces indicates the
number of blanks per fixed tab stop. Gives best fit result
when the length of r exceeds MAX_LINE_LENGTH */
void convert_tabs_to_spaces(char s[], char r[], int tab_stop_spaces)
{
    int length, i, j;
    for(length = 0; s[length] != '\0'; ++length);

    for(i = 0, j = 0; i < length + 1; ++i)
    {
        if (s[i] == '\t')
        {
            /* Tabs are converted into spaces
            that lead up to the next tab stop */
            int number_blanks = tab_stop_spaces - (j % tab_stop_spaces);
            while (number_blanks > 0)
            {
                r[j] = ' ';
                ++j;
                --number_blanks;
            }
        }
        else
        {
            r[j] = s[i];
            ++j;
        }
    }

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
