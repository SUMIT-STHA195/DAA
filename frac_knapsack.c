#include <stdio.h>

// Structure to represent an item
typedef struct
{
    int value;
    int weight;
    float ratio;
} Item;

// Function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b)
{
    return ((Item *)b)->ratio - ((Item *)a)->ratio;
}

// Function to calculate the maximum value in the knapsack
float fractionalKnapsack(int W, Item items[], int n)
{
    qsort(items, n, sizeof(Item), compare);

    int currentWeight = 0;
    float maxValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= W)
        {
            currentWeight += items[i].weight;
            maxValue += items[i].value;
        }
        else
        {
            int remainingWeight = W - currentWeight;
            maxValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }

    return maxValue;
}

int main()
{
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &items[i].value);
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Calculate and print the maximum value
    float maxValue = fractionalKnapsack(W, items, n);
    printf("Maximum value that can be put in the knapsack: %.2f\n", maxValue);

    return 0;
}
