#include<stdio.h>

int main()
{
    int l = 2;
    for(int i=1;i<=4;i++){
    int x =i;
    for(int k=i;k<4;k++){
        printf(" ");
    }
    for(int j=1;j<=i;j++){
        printf("%d",x);
        x++;
    }
    if(i>=2){
        for(int j=2;j<=i;j++){
            printf("%d",l);
            l--;
        }
        l = l + ;
    }
        printf("\n");
   }

   
    return 0;
}