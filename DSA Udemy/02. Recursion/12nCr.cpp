#include <iostream>
using namespace std;

long fact (int n) {
    if(n == 1 || n== 2) return n;
    return n * fact (n-1);
}
double nCr (int n, int r) {
    double den, num = fact (n);
    den = fact (r) * fact (n-r);
    return num / den;
}

double NCR (int n, int r) {
    if (n == r || r == 0) return 1;
    return NCR (n-1, r-1) + NCR (n-1, r);
}

int main () {
    cout <<nCr (4, 2) << " " << NCR (4, 2);
}