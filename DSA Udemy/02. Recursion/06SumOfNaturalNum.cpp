/*This program calculates sum of n natural numbers using three diff approach*/
#include <iostream>
using namespace std;

//using Loop
long NaturalSumLoop (int n) {
    long ans {};
    for(int i = 1; i <= n; i++) 
        ans += i;
    return ans;
}
// using formula
long NaturalSumForm (int n) {
    return n* (n+1) / 2;
}
//Using rec
long nSum(int n) {
    if (n < 1) return 0;
    return nSum (n-1) + n;
}




int main () {
    cout << NaturalSumLoop (5) << " " << NaturalSumForm (5) << " " << nSum (5) << endl;

    return 0;
}