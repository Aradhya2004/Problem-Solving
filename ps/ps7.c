#include<stdio.h>
#include<math.h>

int fact(int n)
{
    if(n<=1){
        return 1;
    }
    return n * fact(n-1);
}
int value(int a,int b)
{
   if(b==1){
    return a;
   }
   else{
    for(int i=1;i<b;i++)
    {
        a = a*a;
    }
    return a;
   }
}
int main()
{
    int n,x;
    double sum = 1;

    scanf("%d %d",&n ,&x);

    for(int i=1;i<=n;i++)
    {
        // if(i%2!=0)
        // {
        //     sum -= value(x,i)/fact(i);
        // }
        // else{
        //     sum += value(x,i)/fact(i);
        // }

        sum += (double)(pow(-x,i)/fact(i));
    }
    printf("%lf", sum);
}