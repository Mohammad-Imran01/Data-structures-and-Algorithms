#include <iostream>
#define size 100
using namespace std;

struct Array {
    int *a = new int[size];
    int n;

    Array(int elements) {
        n = elements;
    }
};
//fills array with values given by user...
void read (Array a) {
    cout << "Enter " << a.n << " elements.\n";
    for(int i = 0; i < a.n; i++)
        cin >> a.a[i];
    return; 
}
//print out elements of the array...
void print (Array a) {
    cout << "\nElements are: ";
    for(int i = 0; i < a.n; i++)
        cout << a.a[i] << ' ';
    cout << '\n';
    return;
}
int main () {
    Array arr(5);

    read(arr);
    print(arr);

    cout << "\nExit Success.";
    return 0;
}