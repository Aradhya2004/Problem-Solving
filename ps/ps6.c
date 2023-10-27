#include<stdio.h>

int factorial(int n)
{
    int f=1;
    while(n>1){
        f *= n--;
    }
    return f;
}
long value(int p,int q)
{
    long a = p;
    while(q>0)
    {
        a = a*p;
        q--;
    }
    return a;
}
int main()
{
    int x,n;
    long sum = 0;
    scanf("%d %d",&x ,&n);

    for(int i=1;i<=n;i++){
        if(i%2 == 0)
        {
            sum -= value(x,i);
        }
        else{
            sum += value(x,i)/factorial(i);
        }
    }
    printf("%ld",sum);
    return 0;
}