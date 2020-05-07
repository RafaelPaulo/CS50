#include <stdio.h>
#include <math.h>

void printArray(int array[], int length);
void mergesort(int array[], int length);
void slice(int originArray[], int array[], int start, int end);

void sort(int merged[], int array[], int length);
void merge(int result[], int left[], int lLength, int right[], int rLength);

int main(void)
{
    int unsortedArray[10] = {3,1,7,2,10,5,4,6,8,9};
    // int unsortedArray[10] = {9,14,7,2,10,5,8,6,11,9};
    int sortedArray[10]   = {1,2,3,4,5,6,7,8,9,10};
    // int unsortedArray[5] = {3,1,2,4,5};

    mergesort(unsortedArray, 10);
    // mergesort(unsortedArray, 5);
    mergesort(sortedArray, 10);
}

void mergesort(int array[], int length)
{   
    int sorted[length];

    sort(sorted, array, length);

    printf("\nSorted: ");
    printArray(sorted, length);
}


void sort(int merged[], int array[], int length)
{
    if (length == 1) {
        merged[0] = array[0];
    } else {
        // devide the array in two halves
        int middle = floor(length / 2),
            lLength = middle,
            rLength = length - middle;

        int left[lLength];
        int right[rLength];

        slice(left, array, 0, middle);
        slice(right, array, middle, length);
        
        int lsorted[lLength];
        int rsorted[rLength];

        sort(lsorted, left, lLength);
        sort(rsorted, right, rLength);

        merge(merged, lsorted, lLength, rsorted, rLength);
    }
}

void merge(int result[], int left[], int lLength, int right[], int rLength)
{   
    int iL = 0,
        iR = 0,
        iM = 0;

    while (iL < lLength && iR < rLength)
    {
        if (left[iL] < right[iR])
            result[iM++] = left[iL++];   
        else
            result[iM++] = right[iR++];
    }

    while (iL < lLength)
    {
        result[iM++] = left[iL++];
    }

    while (iR < rLength)
    {
        result[iM++] = right[iR++];
    }
}

void slice(int originArray[], int array[], int start, int end)
{
    for (int i=start, j=0; i < end; i++)
    {
        originArray[j++] = array[i];
    }
}

void printArray(int array[], int length)
{
    printf("[");
    for (int i = 0; i < length; i++)
        printf(" %i", array[i]);
    printf(" ]\n");
}