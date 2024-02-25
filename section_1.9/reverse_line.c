/* Write a function reverse(s) that reverses
the character string s. Use it to write a
program that reverses its input a line at a
time */

#include <stdio.h>

#define MAX_LINE_LENGTH 1000

/* Might be better to make reverse into
a two argument function, one with input
and one with modified output. But exercise
asks for a single arg function */
void reverse(char line[]);
int get_line_with_arbitrary_length(char s[], int limit);

int main()
{
    int current_length, i;
    char line[MAX_LINE_LENGTH];

    /* Using previously written get_line function */
    while((current_length = get_line_with_arbitrary_length(line, MAX_LINE_LENGTH)) > 0)
    {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

/* reverse takes string s and reverses its contents,
excluding any trailing newline */
void reverse(char s[])
{

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
