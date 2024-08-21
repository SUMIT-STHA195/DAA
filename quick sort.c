
#include <stdio.h>
#include <time.h>

// Global variable to count comparison
int count = 0;

// Function to swap two elements
void swap(int *a, int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}

// Partition function
int partition(int arr[], int left, int right)
{
        // Initialize pivot to be the first element
        int pivot = arr[left];
        int i = left;
        int j = right;

        while (i < j)
        {
                count++;
                // Condition 1: find the first element greater than the pivot (from starting)
                while (arr[i] <= pivot && i <= right - 1)
                {
                        i++;
                        count++; // Increment execution steps for each comparison
                }

                // Condition 2: find the first element smaller than the pivot (from last)
                while (arr[j] > pivot && j >= left + 1)
                {
                        j--;
                        count++; // Increment execution steps for each comparison
                }

                if (i < j)
                {
                        swap(&arr[i], &arr[j]);
                        count++;
                }
        }
        swap(&arr[left], &arr[j]);
        return j;
}

// QuickSort function
void quickSort(int arr[], int left, int right)
{
        if (left < right)
        {
                count++;
                // Call Partition function to find Partition Index
                int partitionIndex = partition(arr, left, right);

                // Recursively call quickSort() for left and right half based on partition Index
                quickSort(arr, left, partitionIndex - 1);
                quickSort(arr, partitionIndex + 1, right);
        }
}
// Driver code
int main()
{
        clock_t st = clock();
        int n;
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
        {
                scanf("%d", &arr[i]);
        }

        // Calling quickSort() to sort the given array
        quickSort(arr, 0, n - 1);

        // Printing the sorted array
        printf("Sorted array: ");
        for (int i = 0; i < n; i++)
        {
                printf("%d ", arr[i]);
        }

        // Calculating and printing the execution time
        // printf("%f", (double)(clock()));
        clock_t et = clock();
        printf("\nThe execution time is: %f seconds\n", (double)(et - st) / CLOCKS_PER_SEC);
        printf("Total comparison steps: %d\n", count);

        return 0;
}
