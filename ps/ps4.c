#include<stdio.h>

int factorial(int n){

    if(n==0){
        return 1;
    }
    return n * factorial(n-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    int k = 1;
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=i;j++)
    //     {
    //         printf("%d ",k);
    //          k++;
    //     }
    //     printf("\n");
    // }

    // for(int i=1;i<=n;i++)
    // {
    //     k=i;
    //     for(int j=1;j<=i;j++){
    //         printf("%d ",k);
    //        k++;
    //     }
    //     printf("\n");
    // }

   for(int i=1;i<=n;i++){
    int k =i;
    for(int k=1;k<=n-i;k++){
        printf(" ");
    }
    for(int j=1;j<=i;j++){
        printf("%d",k);
        k++;
    }
    if(i>=2){
        int l =2*i-2;
        for(int j=2;j<=i;j++){
            printf("%d",l);
            l--;
        }
    }
        printf("\n");
   }

//     for(int i=1;i<=n;i++){
//     int x =i;
//     for(int k=i;k<n;k++){
//         printf(" ");
//     }
//     for(int j=1;j<=i;j++){
//         printf("%d",x);
//         x--;
//     }
//     if(i>=2){
//         int l = 2;
//         for(int j=2;j<=i;j++){
//             printf("%d",l);
//             l++;
//         }
//     }
//         printf("\n");
//    }

// float sum = 0;
// for(int i=1;i<=n;i++){
//     sum = sum + factorial(i)/i;
// }
// printf("%.2f",sum);

    return 0;
}