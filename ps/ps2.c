#include<stdio.h>

void checkTriangle(int a,int b,int c)
{
    if(a+b+c == 180){
        if(a > 0){
            if(b > 0){
                if(c > 0){
                    if( a == 60)
                    {   
                        if(b == 60)
                        {
                            if(c == 60){
                                  printf("Equi");
                            }
                        }
                    }
                    else if(a==90){
                        printf("Right angle");
                    }
                    else if(b==90){
                        printf("Right angle");
                    }
                    else if(c==90){
                        printf("Right angle");
                    }
                    else{
                        printf("Koi aur");
                    }

                }
                 else{
        printf("Invalid Angles");
    }
            }
             else{
        printf("Invalid Angles");
    }
        }
         else{
        printf("Invalid Angles");
    }
    }
    else{
        printf("Invalid Angles");
    }
}
int main(){

    int x,y,z;
    scanf("%d %d %d",& x ,&y ,&z);

    checkTriangle(x,y,z);
    return 0;
}