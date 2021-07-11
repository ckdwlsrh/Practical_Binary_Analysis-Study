#include<stdio.h>

int func(int a) {
    a++;
    return a;
}
int main(int argc,char *argv[]){
    int i;
    scanf("%d",&i);
    i = func(i);
    printf("%d",i);
    return 0;
}