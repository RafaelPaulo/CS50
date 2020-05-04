#include <stdio.h>

void insertionSort(int unsortedArray[], int length);
void printArray(int array[], int length);

int main(void)
{
    int unsortedArray[10] = {2,3,1,4,10,5,7,6,8,9};
    // int unsortedArray[10] = {9,14,7,2,10,5,8,6,11,9};
    insertionSort(unsortedArray, 10);

    int sortedArray[10]   = {1,2,3,4,5,6,7,8,9,10};
    insertionSort(sortedArray, 10);
}

void insertionSort(int array[], int length)
{
    int j, current;

    for (int i = 1; i < length; i++)
    {
        current = array[i];
        j = i;

        while(j>0 && array[j-1] > current)
        {
            array[j] = array[j-1];
            j--;
        }

        array[j] = current;
    }

    printf("\nSorted: ");
    printArray(array, length);
}


void printArray(int array[], int length)
{
    printf("[");

    for (int i = 0; i < length; i++)
        printf(" %i", array[i]);
    
    printf(" ]\n");
}