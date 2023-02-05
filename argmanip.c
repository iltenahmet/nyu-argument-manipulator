#include <stdio.h>
#include "argmanip.h"

char **manipulate_args(int argc, const char *const *argv, int (*const manip)(int))
{
    char** newArgs = (char**)malloc(argc * sizeof(char*));
}

void free_copied_args(char **args, ...)
{
    printf("-Free copied args!-");
    (void)args;
}
