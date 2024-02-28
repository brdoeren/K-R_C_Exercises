/* Write a program _entab_ that replaces strings
of blanks by the minimum number of tabs and blanks
to achieve the same spacing. Use the same tab stops
as for _detab_. When either a tab or a single
blank would suffice to reach a tab stop, which
should be given preference? */

#include <stdio.h>

#define TAB_STOP_SPACES 4
#define MAX_LINE_LENGTH 1000

int get_line_with_arbitrary_length(char s[], int limit);
void convert_spaces_to_tabs(char source[], char result[], int tab_stop_spaces);

int main()
{
    char line[MAX_LINE_LENGTH];
    char converted_line[MAX_LINE_LENGTH];

    while(get_line_with_arbitrary_length(line, MAX_LINE_LENGTH) > 0)
    {
        convert_spaces_to_tabs(line, converted_line, TAB_STOP_SPACES);
        printf("%s", converted_line);
    }

    return 0;
}

/* Takes string s and converts groups of blanks into
tabs to achieve the same spacing based on the given
tab_stop_spaces, and stores the result in string r. */
void convert_spaces_to_tabs(char s[], char r[], int tab_stop_spaces)
{
    int blank_accumulator, i, j;
    blank_accumulator = 0;

    /* Iterate through string without
    calculating length, stops at '\0'
    in the source string so result must
    add '\0' at end */
    for(i = 0, j = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == ' ')
        {
            ++blank_accumulator;

            /* Enough blanks are converted into one tab */
            if (blank_accumulator >= tab_stop_spaces)
            {
                r[j] = '\t';
                ++j;
            }
        }
        else
        {
            /* If not blank, then just take what
            blanks we have and add them to result
            and reset accumulator */
            while(blank_accumulator > 0)
            {
                r[j] = ' ';
                ++j;
                --blank_accumulator;
            }

            r[j] = s[i];
            ++j;
        }
    }
    r[j] = '\0';

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
