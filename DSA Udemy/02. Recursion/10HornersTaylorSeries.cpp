#include <iostream>
using namespace std;

double TaylorSeriesLoop(int x, int n) {
    double ans{1};

    for(int i = n; i > 0; i--) {
        ans = 1 + ans * x/i;
    }
    return ans;
}
double Recursive_E (int x, int n) {
    static double ans{1.0};
    if(n == 0) return ans;
    ans = 1 + ans*x/n;
    return Recursive_E(x, n-1);
}


int main () {

    cout << Recursive_E(1, 10);


    cout << "\nExit Success...\n"; 
    return 0;
}