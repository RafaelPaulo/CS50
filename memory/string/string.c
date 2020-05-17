#include <stdio.h>

// typedef char *string;
// string name = "Rafael";

/**
String

The concept of a string is basically:
    - to have a point (address in memory) to the first char of a "string";
    - we assume the end of a string when we find a special character called "NULL terminator character" ('\0');
    - we can access using array notation.  Ex.: name[0], name[1], and etc.
**/

int main(void)
{
    char *name = "Rafael";

    printf("%s\n", name); // Print the string
    printf("%p\n", name); // Print the pointer (address in memory) to this string. This pointer points to the first char of this string
    printf("%p\n", &name[0]); // Print the address in memory of the first char of this string, which is exactly the same result as the line above

    printf("%c\n", *name); // => R
    // Brackets ([]) is just a syntax sugar to access addresses in memory in a linear way.
    printf("%c\n", *(name+1)); // => a
    printf("%c\n", *(name+2)); // => f
    printf("%c\n", *(name+3)); // => a
    printf("%c\n", *(name+4)); // => e
    printf("%c\n", *(name+5)); // => l
    printf("%c\n", *(name+6)); // => \0

}