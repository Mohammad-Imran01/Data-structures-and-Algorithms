/*Function call itself as parameter */
#include <iostream>
using namespace std;

int nested (int n) {
    if (n > 100) return n-10;
    else return nested ((nested (n+11)));
}


int  main () {
    cout << nested (111111);
}