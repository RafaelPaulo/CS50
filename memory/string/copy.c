#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    // same as:
    //      typedef char *string;
    //      string name = get_string("What's your name?\n");
    char *name = get_string("\nWhat's your name?\n");
    // alloc memory. The extra number 1 is to fit the NULL terminator character.  
    char *nameCopy = malloc(strlen(name) + 1);
    // If the computer was NOT able to hand you a pointer, it will return a NULL pointer.
    // You should always make sure that it is not a NULL pointer to proceed.
    if (s != NULL)
    {
        return 1;
    }

    // Copying from name to nameCopy
    // same as: strcpy(nameCopy, name);
    for (int i = 0, length = strlen(name); i <= length; i++)
    {
        // same as:
        // nameCopy[i] = name[i]
        *(nameCopy+i) = *(name+i);
    }

    nameCopy[0] = toupper(nameCopy[0]);

    printf("name: %s\n",  name);
    printf("nameCopy: %s\n",  nameCopy);

    // Free up memory
    free(nameCopy);
}