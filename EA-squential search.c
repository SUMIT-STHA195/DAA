#include <stdio.h>
int main()
{
        int a[100], n, i, count = 0, key, found = 0;
        printf("Enter number of elements: ");
        scanf("%d", &n);
        printf("Enter %d elements: ", n);
        count = count + 7;
        for (i = 0; i < n; i++)
        {
                scanf("%d", &a[i]);
                count += 4;
        }
        // Sequential Search Algorithm
        printf("Enter element to search: ");
        scanf("%d", &key);
        count += 5;
        for (i = 0; i < n; i++)
        {
                count += 4;
                if (a[i] == key)
                {
                        found = 1;
                        break;
                        count = count + 3;
                }
        }
        count = count + 2;
        if (found)
        {
                printf("Element %d found at position %d\n", key, i + 1);
                count += 2;
        }
        else
        {
                printf("Element %d not found\n", key);
                count += 2;
        }

        printf("Total execution steps = %d", count);
        count += 3;
        return 0;
}
