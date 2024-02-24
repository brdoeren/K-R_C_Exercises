/* Write a function reverse(s) that reverses
the character string s. Use it to write a
program that reverses its input a line at a
time */

#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int reverse(char line[]);

int main()
{
    int current_length, i;
    char line[MAX_LINE_LENGTH];

    while((current_length = reverse(line)) > 0)
    {
        printf("%s\n", line);
    }

    return 0;
}

/* reverse takes string s and reverses its contents,
excluding any trailing newline;
it returns the length of the line */
int reverse(char s[])
{
    return 0;
}
