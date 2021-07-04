#include<stdio.h>

int main(int argc,char *argv[]) {
    int n = 1;
    int sum = 0;
    while(n <= 10) {
        sum +=n;
        n++;
    }
    printf("%d", sum);
    return 0;
}