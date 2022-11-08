/*Example of nested recursion meaning a function calls itself more than one time*/
#include <iostream>
using namespace std;

void IamNested(int num) {
    if(num < 1) return ;
    cout << num << ' ';
    IamNested (num - 1);
    IamNested (num - 1);
}

unsigned long long fib (int num) {
    if (num < 1) return 0;
    if(num == 1 || num == 2) return 1;
    return fib (num-1) + fib (num-2);
}

int main () {
    cout << fib (45);
    return 0;
}