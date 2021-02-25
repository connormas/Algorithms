// BUBBLE SORT

#include <stdio.h>

void swap(int*,int*);

void bubblesort(int arr[], int size)
{
    int i, j;
    for (i = 0;  i < size - 1; i++)     //  Function where the actual algorithm is implemented
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
 
        }
    }
}
void swap(int *a, int *b)
{
    int temp;                         // Function for swapping two variables
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    //int nts = 550000;  // 0.65 IPC
    int nts = 1000000;   // 0.56 IPC
    int array[nts], size;
    size = nts;
    int j = 0;
    for (int i = nts; i >= 0; i--) {
      array[j] = i;
      j++;
    }
    bubblesort(array, size);
    printf("\nSorted array is ");
 
    for (int i = 0; i < size; i++)
        printf(" %d ", array[i]);
    printf(" ");
    return 0;
 
}

