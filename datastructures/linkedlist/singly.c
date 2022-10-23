#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int number;
    struct node *next;
}
node;

int ladd(node **list, int value)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {   
        return 1;
    }

    // set the next node to NULL
    // -> is just a sintax suggar for (*n).
    n->next = NULL;
    n->number = value;

    // 1- add the new node n into the list provided
    // 1.1- verify if the list is empty
    if (list == NULL)
    {
        (*list) = n;
        return 0;
    }

    n->next = (*list);
    (*list) = n;

    return 0;
}

void lprint(node *list)
{
    // verify is it is an empty list
    if (list == NULL)
    {
        return;
    }
    lprint(list->next);
    printf("-> %i\n", list->number);
}

void lfree(node *list)
{
    // verify is it is an empty list
    if (list != NULL)
    {
        lfree(list->next);
        free(list);
    }
}

int main(int argc, char *argv[])
{
    node *list = NULL;

    ladd(&list, 1);
    ladd(&list, 2);
    ladd(&list, 3);
    ladd(&list, 4);

    lprint(list);

    lfree(list);
}