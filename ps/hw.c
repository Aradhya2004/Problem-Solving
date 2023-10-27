#include<stdio.h>

int sum(int n)
{
   if(n == 0) return 0;

   return n%10 + sum(n/10);
}

int main()
{
    int n;
    int a,b;
    scanf("%d",&n);

    int s = sum(n);
    printf("Sum of digits of %d is %d",n,s);


    return 0;
}