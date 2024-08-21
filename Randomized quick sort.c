#include <stdio.h>
#include <stdlib.h>
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
        int pivot = arr[right]; // Pivot element at the end
        int i = left - 1;

        for (int j = left; j <= right - 1; j++)
        {

                if (arr[j] <= pivot)
                {
                        i++;
                        swap(&arr[i], &arr[j]);
                }
        }
        swap(&arr[i + 1], &arr[right]);
        return (i + 1);
}

// Function to generate a random pivot
int randomPartition(int arr[], int left, int right)
{
        int randomIndex = left + rand() % (right - left + 1);
        swap(&arr[randomIndex], &arr[right]);
        return partition(arr, left, right);
}

// Randomized QuickSort function
void quickSort(int arr[], int left, int right)
{
        if (left < right)
        {
                int partitionIndex = randomPartition(arr, left, right);

                quickSort(arr, left, partitionIndex - 1);
                quickSort(arr, partitionIndex + 1, right);
        }
}

// Driver code
int main()
{
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
        return 0;
}
