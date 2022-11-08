#include <iostream>
using namespace std;

//RECURSIVE
long fib (int n) {
    if (n < 2) return n;
    return fib(n-1) + fib (n-2);
}
//LOOP
long fib2(int n) {
    if (n < 2) return n;
    int f0{}, f1{1};
    long ans{};
    for(int i = 2; i <= n; i++) {
        ans = f0+f1;
        f0 = f1;
        f1 = ans;
    }
    return ans;
}

//Memoized Recursion 
long fib3(int n) {
    static int mem[5000];
    if (n <= 1) {
        mem[n] = n;
        return n;
    } else {
        if(mem[n-1] == 0) mem[n-1] = fib3(n-1);
        if(mem[n-2] == 0) mem[n-2] = fib3(n-2);
 
        return mem[n-1] + mem[n-2];
    }     
}

int main () {
    for(int i = 2; i < 10; i ++)
    cout << i << ". "  << "Rec: " << fib (i) << "  Loop: " << fib2(i) << "  Mem: " << fib3(i) << endl;

}