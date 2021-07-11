#include <iostream>

using namespace std;

int func(int a) {
    a++;
    return a;
}
int main(int argc,char *argv[]){
    int i;
    cin >> i;
    i = func(i);
    cout << i;
    return 0;
}