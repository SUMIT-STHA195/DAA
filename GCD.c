
#include <stdio.h>
// Function to compute GCD using the Euclidean algorithm
int gcd(int a, int b)
{
       if(b==0){
                return a;
        }
        else{
                return gcd(b,a%b);
        }
}

int main()
{
        int num1, num2;
        // Get input from the user
        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);
        // Calculate and display the GCD
        printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
        return 0;
}
