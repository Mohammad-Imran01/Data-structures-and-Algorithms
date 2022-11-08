/*A function calls another function, and vice versa or function calling each other in a circular manner*/

#include <iostream>
using namespace std;

void funB (int );
void funA (int a) {
    if (a < 1) return ;
    cout << a << ' ';
    funB(a -1);
}
void funB (int b) {
    if (b < 1) return;
    cout << b << ' ';
    funA (b/2);
}

int main () {
    funA (50);
}