#include<stdio.h>
#include<math.h>

int fact(int n)
{
    if(n<=1){
        return 1;
    }
    return n * fact(n-1);
}

int main()
{
    int n,x;
    double sum = 0;
    int op = -1;

    scanf("%d %d",&n ,&x);

    for(int i=1;i<=n;i=i+2)
    {
        sum += ((double)(pow(-x,i)/fact(i)))*op;
    }
    printf("%lf", sum);
}