#include <stdio.h>

void selectionSort(int array[], int length);
void printArray(int array[], int length);
void swap(int *smaller, int *bigger);

int main(void)
{
    // int unsortedArray[10] = {3,1,7,2,10,5,4,6,8,9};
    int unsortedArray[10] = {9,14,7,2,10,5,8,6,11,9};
    // int sortedArray[10]   = {1,2,3,4,5,6,7,8,9,10};

    selectionSort(unsortedArray, 10);
    // selectionSort(sortedArray, 10);
}

void selectionSort(int array[], int length)
{
    int smallestIndex;

    for (int i = 0; i < length; i++)
    {
        // reset smallest index
        smallestIndex = i;

        for (int j = i+1; j < length; j++)
        {
            if (array[j] < array[smallestIndex])
                smallestIndex = j;
        }
        
        if (smallestIndex >= 0)
            swap(&array[smallestIndex], &array[i]);
    }

    printf("\nSorted: ");
    printArray(array, length);
}

void swap(int *v1, int *v2)
{
    int smaller = *v1;
    *v1 = *v2;
    *v2 = smaller;
}

void printArray(int array[], int length)
{
    printf("[");

    for (int i = 0; i < length; i++)
        printf(" %i", array[i]);
    
    printf(" ]\n");
}
