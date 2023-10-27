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

    scanf("%d",&n);
    int j = 1;
    for(int i=1;i<=n;i++)
    {
        op *= -1;
        sum += ((double)(i/fact(j)))*op;
        j += 2;
    }
    printf("%lf", sum);
}