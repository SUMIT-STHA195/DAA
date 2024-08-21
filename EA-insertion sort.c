#include <stdio.h>
int main()
{
        int a[100], n, i, j, key, count = 0;
        printf("Enter number of elements: ");
        scanf("%d", &n);
        printf("Enter %d elements: ", n);
        count = count + 7;
        for (i = 0; i < n; i++)
        {
                scanf("%d", &a[i]);
                count = count + 4;
        }
        count = count + 3;
        for (i = 1; i < n; i++)
        {
                key = a[i];
                j = i - 1;
                count = count + 7;

                while (j >= 0 && a[j] > key)
                {
                        a[j + 1] = a[j];
                        j = j - 1;
                        count = count + 3;
                }
                a[j + 1] = key;
                count = count + 2;
        }
        printf("Elements in sorted order: ");
        count = count + 4;
        for (i = 0; i < n; i++)
        {
                printf("%d ", a[i]);
                count = count + 4;
        }
        printf("\nTotal execution steps = %d\n", count);
        count = count + 3;
        return 0;
}
