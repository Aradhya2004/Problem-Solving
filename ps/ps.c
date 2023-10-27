#include<stdio.h>

void checkTriangle(int a, int b , int c)
{
    if(a == b)
    {
        if(a == c){
            printf("Equilateral triangle");
        }
        else{
            printf("Isosceles Triangle");
        }
    }
    else if(a == c){
        printf("Isoceles");
    }
    else if(b == c){
        printf("Isoceles");
    }
    else{
        printf("Scalene");
    }

}
void pattern(int n){
    int k = 1;
    for(int i=1;i<=n;i++){
        if(i == 2){
            k = 2;
        }
        for(int j=1;j<=i;j++){
            printf("%d",k);
                k++;
        }
        printf("\n");
        k--;
    }
}
int main()
{
    int x,y,z;
    int n;
    // printf("Enter three sides of a triangle");
    // scanf("%d %d %d",&x ,&y ,&z);

    // checkTriangle(x,y,z);
    scanf("%d",&n);
    pattern(n);
    return 0;
}