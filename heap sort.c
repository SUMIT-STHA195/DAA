#include <stdio.h>
// Function to swap two elements
void swap(int *a, int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}

// Heapify function
void heapify(int arr[], int n, int i)
{
        int largest = i;       // Initialize largest as root
        int left = 2 * i + 1;  // left child
        int right = 2 * i + 2; // right child

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
        {
                largest = left;
        }
        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
        {
                largest = right;
        }
        // If largest is not root
        if (largest != i)
        {
                swap(&arr[i], &arr[largest]);

                // Recursively heapify the affected sub-tree
                heapify(arr, n, largest);
        }
}

// HeapSort function
void heapSort(int arr[], int n)
{
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
                heapify(arr, n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--)
        {
                // Move current root to end
                swap(&arr[0], &arr[i]);
                // Call max heapify on the reduced heap
                heapify(arr, i, 0);
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

        // Calling heapSort() to sort the given array
        heapSort(arr, n);

        // Printing the sorted array
        printf("Sorted array: ");
        for (int i = 0; i < n; i++)
        {
                printf("%d ", arr[i]);
        }
        return 0;
}
