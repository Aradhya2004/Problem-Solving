#include<stdio.h>

void check(int a,int b)
{
    if(a>0)
    {
        if(b>0){
            printf("First Quad");
        }
        else if(b<0){
            printf("Fourth Quad");
        }
        else{
            printf("X axis");
        }
    }
    else if(a<0){
        if(b>0){
            printf("Sec Quad");
        }
        else if(b<0){
            printf("Third");
        }
        else{
            printf("X axis");
        }
    }
    else{
        if(b==0){
            printf("Origin");
        }
        else{
            printf("Y axis");
        }
    }
  
}
int main()
{
    int x,y;
    scanf("%d %d",&x ,&y);
    check(x,y);
    return 0;
}