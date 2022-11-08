//Implements array in heap and stack as well

#include <iostream>
#include <string.h>
using namespace std;

//This function print elements present in array
void print(int array[], int arraysize) {
    for(int i = 0; i < arraysize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
 
int main () {

    //stack
    int a[] {2, 4, 1, 3, 5};
    int asize = sizeof(a)/sizeof(a[0]);
    
    //heap
    int* b = new int[10],
    bsize = sizeof(b)/sizeof(b[0]);
    memcpy(b,a,10);

    print(a, asize);
    print(b, bsize);

    return 0;
}