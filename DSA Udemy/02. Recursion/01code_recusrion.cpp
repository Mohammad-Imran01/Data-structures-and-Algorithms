#include <iostream>
using namespace std;

/*Do all Works then call yourself*/
void tailRecursion (int num) {
    if (num <= 0) return;
    cout << num << " ";
    tailRecursion (num - 1);
}

/*call yourself then Do all Works*/
void headRecursion (int num) {
    if (num <= 0) return;
    headRecursion (num - 1);
    cout << num << " " ;
}

int main () {
    headRecursion (5);
    cout << '\n' ;
    tailRecursion (5);
}