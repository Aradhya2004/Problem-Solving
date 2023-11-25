#include<stdio.h>
#include<malloc.h>
struct node{
    int info;
    struct node *next;
};

void incr1(int *num){
    *num=*num+10;
}
void incr2(struct node **temp){
    (*temp)->info=(*temp)->info+20;
}
int main(){
   
    int num=50;
    incr1(&num);
    printf("num=%d\n",num);
    struct node *s=(struct node *)malloc(sizeof(struct node));
    s->info=100;
    incr2(&s);
    printf("%d",s->info);
    return 0;
}
