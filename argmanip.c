#include <stdio.h>
#include "argmanip.h"

char **manipulate_args(int argc, const char *const *argv, int (*const manip)(int))
{
    printf("-Manipulate Args!-");
    (void)argc;
    (void)argv;
    (void)manip;
    char c = 'c';
    char* pointer = &c;
    char** pointer2 = &pointer;
    return pointer2;
}

void free_copied_args(char **args, ...)
{
    printf("-Free copied args!-");
    (void)args;
}