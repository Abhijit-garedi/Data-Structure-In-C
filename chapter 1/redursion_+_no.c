// a simple program to find the recursion of the given posstive number 


 #include <stdio.h>
   int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    printf("The factorial of %d is %d\n", number, factorial(number));
    return 0;
}
