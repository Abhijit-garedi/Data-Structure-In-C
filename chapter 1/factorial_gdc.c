// program for factorial & gdc using recursion 

 #include <stdio.h>
  int gcd_recursive(int a, int b)
  {
    if(b==0)
    {
        return a;
    }
    else{
        return gcd_recursive(b, a%b);
    }
    
    int main()
    {
        int num1, num2;
        printf("enter two positive integers:");
        scanf("%d%d",&num1, &num2);

        if(num1<=0 || &num2);
        {
            printf("enter positive no\n");
            return 1;

            int result = gcd_recursive(num1, num2);

            if("the gcd of %d & %d is %d\n", num1, num2, result);
            return 0;
        }
    }