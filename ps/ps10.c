#include<stdio.h>

int main()
{
    int arr[3][3],sum1=0,sum2 = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&arr[i][j]);
        }
    }

// Sum of diagonal elements

    for(int i=0;i<3;i++){
        sum1 += arr[i][i];
        sum2 += arr[i][3-i-1];
    }
    printf("%d",sum1+sum2);
}