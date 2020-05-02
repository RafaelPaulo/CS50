#include <stdio.h>

// prototypes
void bubbleSort(int unsortedArray[], int length);
void printArray(int array[], int length);
void swap(int *bigger, int *smaller);

int main(void)
{
    int unsortedArray[10] = {3,1,7,2,10,5,4,6,8,9};
    // int unsortedArray[10] = {9,14,7,2,10,5,8,6,11,9};
    bubbleSort(unsortedArray, 10);

    int sortedArray[10]   = {1,2,3,4,5,6,7,8,9,10};
    bubbleSort(sortedArray, 10);
}

// implementation
void bubbleSort(int array[], int length)
{   
    int swapCounter = -1,
        maxIndex = length,
        iterations = 0; // Just for learning purposes

    while (swapCounter > 0 || swapCounter == -1)
    {
        swapCounter = 0;
        for (int i = 0; i < (maxIndex-1); i++)
        {
            if (array[i] > array[i+1])
            {
                swap(&array[i], &array[i+1]);
                swapCounter++;
            }
        }
        maxIndex--;
        iterations++;
    }

    printf("Iterations: %i\n", iterations);
    printf("Sorted! \n");
    printArray(array, length);
}

void swap(int *p1, int *p2)
{
    int bigger = *p1;
    *p1 = *p2;
    *p2 = bigger;
}

void printArray(int array[], int length)
{
    printf("[");

    for (int i = 0; i < length; i++)
        printf(" %i", array[i]);
    
    printf(" ]\n");
}
