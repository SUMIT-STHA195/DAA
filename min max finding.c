#include <stdio.h>

// Function to find the minimum and maximum elements in an array
void findMinMax(int arr[], int n, int *min, int *max)
{
        *min = arr[0];
        *max = arr[0];

        for (int i = 1; i < n; i++)
        {

                if (arr[i] < *min)
                {
                        *min = arr[i];
                }
                if (arr[i] > *max)
                {
                        *max = arr[i];
                }
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
        int min, max;
        // Calling findMinMax() to find the minimum and maximum elements in the array
        findMinMax(arr, n, &min, &max);

        // Printing the minimum and maximum elements
        printf("Minimum element: %d\n", min);
        printf("Maximum element: %d\n", max);
        return 0;
}
