#include <iostream>
using namespace std;
/*
This program shows different implementations of array in cpp
*/


//function to print array elements
void print (int array[], int arraysize) {
    for(int i = 0; i < arraysize; i++) {
        cout << array[i] << " " ;
    }
    cout << endl;
}


int main () {
    int a[]{1, 2, 3, 4},
    b[5]{},
    c[5]{0};

    for(int i = 0; i < 4; i++) {
        cout << a[i] << ' ';
    } cout << endl;

    cout << b[1] << endl;
    cout << c[1] << endl;

    print(a, 4);

    return 0;
}