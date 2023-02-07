#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "argmanip.h"

char **manipulate_args(int argc, const char *const *argv, int (*const manip)(int))
{
    char** manipulatedArgs = (char**) malloc((argc + 1) * sizeof(char*));

    for (int i = 0; i < argc; i++)
    {
        const char* oldStr = argv[i];
        int length = strlen(oldStr) + 1;
        char* newStr = (char*)malloc(length);

        for (int j = 0; j < length; j++)
        {
            newStr[j] = manip(oldStr[j]);
        }

        manipulatedArgs[i] = newStr;
    }

    manipulatedArgs[argc] = NULL;

    return manipulatedArgs;
}

void free_copied_args(char **args, ...)
{
    va_list list;
    va_start(list, args);

    char** current = args;
    while (current != NULL)
    {
        for(int i = 0; current[i] != NULL; i++)
        {
            free(current[i]);
        }
        free(current);
        current = va_arg(list, char**);
    }

    va_end(list);
}
