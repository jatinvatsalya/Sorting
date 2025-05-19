// Online C compiler to run C program online
#include <stdio.h>
#include <stdio.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main() {
    // Write C code here
    printf("Hello\n");
    int arr[6] = {7,4,3,8,2,6};

    bubbleSort(arr, 6);
    selectionSort(arr, 6);
    insertionSort(arr, 6);

    return 0;
}

/*Start from the second element (index 1), assuming the first element is already sorted.
Compare the current element with the elements before it.
Shift all larger elements one position to the right.
Insert the current element into its correct position in the sorted part.
Repeat for all elements until the array is sorted.*/
void insertionSort(int arr[], int n)
{
    int i;
    int j;
    int key;

    printf("\nInsertion Sort\n");
    for ( i = 1; i < n; ++i )
    {
        key = arr[i];
        j = i - 1;
        
        while ( j >= 0 && arr[ j ] > key )
        {
            arr[ j + 1 ] = arr[ j ];
            --j;
        }
        arr[ j + 1 ] = key;
    }
    
    for ( i = 0; i < n; ++i )
    {
        printf(" %d ", arr[i] );
    }
}

/*Start with the first element of the array.
Find the smallest element in the unsorted portion of the array.
Swap it with the first element.
Move to the next position and repeat the process for the remaining unsorted part.
Continue until the entire array is sorted.*/
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    printf("\nselction Sort\n");
    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        // Find the minimum element in the unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    for ( i = 0; i < n; ++i )
    {
        printf(" %d ", arr[i] );
    }
}

/*How it works:
Start at the beginning of the array.
Compare the first two elements.
If the first is greater than the second, swap them.
Move to the next pair and repeat until the end of the array.
After each full pass, the largest unsorted element "bubbles up" to its correct position.
Repeat the process for the remaining unsorted part of the array.*/
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    printf("\nBubble Sort\n");
    for (i = 0; i < n - 1; i++) {
        swapped = 0;

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped in the inner loop, break
        if (swapped == 0)
            break;
    }
    for ( i = 0; i < n; ++i )
    {
      printf(" %d ", arr[i] );
    }
}
