#include <stdio.h>
// Merge function
void merge(int arr[], int left, int mid, int right)
{
        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temp arrays
        int L[n1], R[n2];

        // Copy data to temp arrays L[] and R[]
        for (i = 0; i < n1; i++)
                L[i] = arr[left + i];
        for (j = 0; j < n2; j++)
                R[j] = arr[mid + 1 + j];

        // Merge the temp arrays back into arr[left..right]
        i = 0;    // Initial index of first subarray
        j = 0;    // Initial index of second subarray
        k = left; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
                if (L[i] <= R[j])
                {
                        arr[k] = L[i];
                        i++;
                }
                else
                {
                        arr[k] = R[j];
                        j++;
                }
                k++;
        }

        // Copy the remaining elements of L[], if there are any
        while (i < n1)
        {
                arr[k] = L[i];
                i++;
                k++;
        }

        // Copy the remaining elements of R[], if there are any
        while (j < n2)
        {
                arr[k] = R[j];
                j++;
                k++;
        }
}

// MergeSort function
void mergeSort(int arr[], int left, int right)
{
        if (left < right)
        {
                int mid = left + (right - left) / 2;

                // Recursively call mergeSort for left and right halves
                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);

                // Merge the sorted halves
                merge(arr, left, mid, right);
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

        // Calling mergeSort() to sort the given array
        mergeSort(arr, 0, n - 1);

        // Printing the sorted array
        printf("Sorted array: ");
        for (int i = 0; i < n; i++)
        {
                printf("%d ", arr[i]);
        }
        printf("\n");
        return 0;
}
