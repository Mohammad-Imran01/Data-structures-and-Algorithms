#include <iostream>
using namespace std;

void TOH (int disc, int a, int b, int c) {
    if (disc) {
        TOH (disc-1, a, c, b);
        cout << "(" << a << ", " << c << ")\n";
        TOH (disc-1, b, a, c);
    }
}

int main () {
    TOH (10, 1, 2, 3);
}