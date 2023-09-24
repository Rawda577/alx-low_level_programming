#include <stdio.h>

void print_message(void) __attribute__ ((constructor));

/**
 * print_message - Prints a message before main function is executed
 */
void print_message(void)
{
    printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}

int main(void)
{
    printf("(A tortoise, having pretty good sense of a hare's nature, challenges one to a race.)\n");
    return 0;
}

