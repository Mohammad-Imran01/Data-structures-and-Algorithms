/*This program calculates n factorial using loop and recursion approach*/
#include <iostream>
using namespace std;

//using Loop
long long Loopfact (int n) {
    long long ans {1};
    for(int i = 1; i <= n; i++) 
        ans *= i;
    return ans;
}
//Using rec
long long fact(int n) {
    if (n == 1) return 1;
    return fact (n-1) * n;
}




int main () {
    cout << fact (5) << " " << Loopfact (5) << endl;

    return 0;
}