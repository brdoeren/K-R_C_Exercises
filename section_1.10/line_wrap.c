/* Write a program to "fold" long input lines
into two or more shorter lines after the last
non-blank character that occurs before the
n-th column of input. Make sure your program
does something intelligent with very long
lines, and if there are no blanks or tabs
before the specified column. */

#include <stdio.h>

#define MAX_LINE_LENGTH 1000
#define DESIRED_LINE_LENGTH 10 // Short for debugging purposes

int get_line_with_arbitrary_length(char s[], int limit);
void fold_long_line(char source[], char result[], int line_wrap);

int main()
{
    char line[MAX_LINE_LENGTH];
    char folded_line[MAX_LINE_LENGTH];

    while(get_line_with_arbitrary_length(line, MAX_LINE_LENGTH) > 0)
    {
        //printf("%s", line);
        fold_long_line(line, folded_line, DESIRED_LINE_LENGTH);
        printf("%s", folded_line);
    }

    return 0;
}

/* Takes string s and splits it into multiple
lines based on value of line_wrap; stores result
in string r. */
void fold_long_line(char s[], char r[], int line_wrap)
{
    int i, j, length_accumulator, char_accumulator;
    length_accumulator = 0;
    char_accumulator = 0;

    for(i = 0, j = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == ' ' || s[i] == '\n')
        {
            /* ONLY copy to result when we find blank
            so char_accumulator is run down every time
            we run into blank */

            /* Preform split if necessary
            else reset char accumulator
            and copy as normal */
            if (length_accumulator >= line_wrap)
            {
                printf("line break with len_acc: %2d, char_acc: %2d\n", length_accumulator, char_accumulator);

                length_accumulator = 0;
                r[j] = '\n';
                ++j;
            }
            while (char_accumulator > 0)
            {
                r[j] = s[i - char_accumulator];
                ++j;
                --char_accumulator;
            }
            ++length_accumulator;
            r[j] = s[i];
            ++j;

        }
        /* If current char is not blank
        keep track of current length of chars
        so that if the length of line exceeds
        desired length, the current group of
        chars can be moved to the new line */
        else
        {
            ++char_accumulator;
            ++length_accumulator;
            /* Account for special case where
            the group of chars are greater
            than the desired length of a line */
            if (char_accumulator >= line_wrap)
            {
                while (char_accumulator > line_wrap - 1)
                {
                    r[j] = s[i - char_accumulator];
                    ++j;
                    --char_accumulator;
                }

                r[j] = '-';
                ++j;
                r[j] = '\n';
                ++j;
                length_accumulator = 0;
            }
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
