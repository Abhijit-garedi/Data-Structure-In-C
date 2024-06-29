// c program to find the gdc of 2 positive number 


 #include <stdio.h>

// Function to find GCD using recursion
int gcd(int a, int b) {
    // Base case: if b is 0, return a
    if (b == 0)
        return a;
    // Recursive case: call gcd with b and the remainder of a divided by b
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    
    // Taking input from user
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);
    
    // Finding and printing GCD
    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    
    return 0;
}
