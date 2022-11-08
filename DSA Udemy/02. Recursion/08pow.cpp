/*Program for getting m raised to the pow of n*/
#include <iostream>
using namespace std;

unsigned long long pow1 (int num, int p=1) {
    if (!p) return 1;
    return num * pow1 (num, p-1);
}

unsigned long long pow (int num, int p=1) {
    if (!p) return 1;
    if(p&1)
        return num * pow (num*num, (p-1)/2);
    else return  pow (num*num, p/2);    
}

int main () {
    cout << pow (2, 9);
}