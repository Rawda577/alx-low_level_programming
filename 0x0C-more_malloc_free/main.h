#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>

int _putchar(char C);
void _puts(char *str);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _atoi(const char *s);
void print_int(unsigned long int n);
void *_memset(char *s, char b, unsigned int n);

#endif
