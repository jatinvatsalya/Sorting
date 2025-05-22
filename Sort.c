// Online C compiler to run C program online
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSortMain(int arr[], int n);
void swap(int * a, int * b);
void quickSortMain( int arr[], int n );

int main() {
    // Write C code here
    printf("Hello\n");
    int arr1[8] = {8,7,6,5,4,3,2,1};
    int arr2[8] = {8,7,6,5,4,3,2,1};
    int arr3[8] = {8,7,6,5,4,3,2,1};
    int arr4[8] = {8,7,6,5,4,3,2,1};
    int arr5[8] = {8,7,6,5,4,3,2,1};

    bubbleSort(arr1,8);
    selectionSort(arr2, 8);
    insertionSort(arr3, 8);
    mergeSortMain(arr4, 8);
    quickSortMain(arr5, 8);

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
    int swaps = 0;

    printf("\nInsertion Sort\n");
    for ( i = 1; i < n; ++i )
    {
        key = arr[i];
        j = i - 1;
        
        while ( j >= 0 && arr[ j ] > key )
        {
            arr[ j + 1 ] = arr[ j ];
            --j;
            ++swaps;
        }
        arr[ j + 1 ] = key;
    }
    
    for ( i = 0; i < n; ++i )
    {
        printf(" %d ", arr[i] );
    }
    printf("\n swaps = %d\n", swaps);
}

/*Start with the first element of the array.
Find the smallest element in the unsorted portion of the array.
Swap it with the first element.
Move to the next position and repeat the process for the remaining unsorted part.
Continue until the entire array is sorted.*/
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    int swaps = 0;

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
            swap(&arr[i], &arr[minIndex]);
            ++swaps;
        }
    }
    for ( i = 0; i < n; ++i )
    {
        printf(" %d ", arr[i] );
    }
    printf("\n swaps = %d\n", swaps);
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
    int swaps = 0;

    printf("\nBubble Sort\n");
    for (i = 0; i < n - 1; i++) {
        swapped = 0;

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
                ++swaps;
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
    printf("\n swaps = %d\n", swaps);
}

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int size = right - left + 1;
    int *temp = (int *)malloc(size * sizeof(int));

    while (i <= mid && j <= right) {
      if (arr[i] <= arr[j])
        temp[k++] = arr[i++];
      else
       temp[k++] = arr[j++];
    }

    while (i <= mid)
       temp[k++] = arr[i++];
    while (j <= right)
       temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
       arr[i] = temp[k];

    free(temp);
}

// Recursive merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

       // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

/*The mergeSort function recursively divides the array.
The merge function combines two sorted halves.
This version is elegant and easy to understand, but it uses the call stack, which may be a concern in memory-constrained environments.*/
void mergeSortMain(int arr[], int n)
{
    int i = 0;
    printf("\nMerge Sort\n");
    mergeSort(arr, 0, n-1);
    for ( i = 0; i < n; ++i )
    {
      printf(" %d ", arr[i] );
    }
}

void swap(int * a, int * b)
{
    int temp;
    
    if ( a != b )
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[ end ];
    int i = start - 1;
    int j = start;
    
    for ( j = start; j < end; ++j )
    {
        if ( arr[j] < pivot )
        {
            ++i;
            swap( &arr[i], &arr[j] );
        }
    }
    swap(&arr[i+1], &arr[end]);
    
    return i+1;
}

void quickSort(int arr[], int start, int end)
{
    int pivot;
    if ( start <= end )
    {
        pivot = partition(arr, start, end);
        
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

/*Quick sort is a fast sorting algorithm that works like this:

1. **Pick a pivot** element from the array.
2. **Partition** the array into two parts:
   - Elements less than the pivot go to the left.
   - Elements greater go to the right.
3. **Recursively** apply the same steps to the left and right parts.

It’s efficient, with average time complexity **O(n log n)**.*/
void quickSortMain( int arr[], int n )
{
    int i = 0;
    printf("\nQuick Sort\n");
    quickSort(arr, 0, n-1);
    for ( i = 0; i < n; ++i )
    {
      printf(" %d ", arr[i] );
    }
}
