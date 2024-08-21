#include <stdio.h>
#include<math.h>
int binarySearch(int arr[], int left, int right, int x)
{
        while (left <= right)
        {

                int mid = (left+right)/ 2;

                // Check if x is present at mid
                if (arr[mid] == x)
                {
                        return mid;
                }

                // If x greater, ignore left half
                if (arr[mid] < x)
                {
                        left = mid + 1;
                }
                // If x is smaller, ignore right half
                else
                {
                        right = mid - 1;
                }
        }

        // If we reach here, then the element was not present
        return -1;
}

int main()
{
        int x,n;
        int arr[]={10,14,19,26,31,42,44};
        n=sizeof(arr)/sizeof(arr[0]);
        printf("Enter the element to search: ");
        scanf("%d", &x);

        int result = binarySearch(arr, 0, n - 1, x);

        if (result == -1)
        {
                printf("Element is not present in array\n");
        }
        else
        {
                printf("Element is present at index %d\n", result);
        }
        return 0;
}
