#include <stdio.h>
#include <cs50.h>

typedef char *string;

int main(void)
{
    string name1 = get_string("name: ");
    string name2 = get_string("name: ");

    // Will always be FALSE because we are comparing addresses in the memory instead of actual values.
    if (name1 == name2)
    {
        // This will never be executed.
        printf("%s\n", "TRUE");
    }
    else
    {
        // Will always be executed.
        printf("%s\n", "FALSE");
    }

    printf("%p - %s\n", name1, name1);
    printf("%p - %s\n", name2, name2);
}