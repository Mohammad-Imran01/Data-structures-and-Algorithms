#include <iostream>
#define size 100
using namespace std;

//A structure consisting of an dynamic array and n - (no of elements present)
struct Array {  
    int *a = new int[size];
    int n;

    Array(int elements) {
        n = elements;
    }
};
//fills array with values given by user...
void read (Array &a) {
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
//Insert/appends an val at the end
void append (Array &a, int val) {
    if(a.n < size)
        a.a[a.n++] = val;
    else
        return;
}
//Insert val at given position...
void set (Array &a, int val, int pos) {
    if (pos > a.n || pos < 0 || pos >= size) return;
    else if (pos == a.n) {
        a.a[a.n++] = val;
    } else {
        a.a[pos] = val;
    }
}
//returns value present at asked index
int get (Array& a, int ind) {
    if (ind < 0 || ind >= a.n) return -1;
    return a.a[ind];
}
/* delete val at given index(0-based). Note: no value is returned use get function if value is required*/
void pop (Array &a, int index) {
    if (index < 0 || index >= a.n) return;
    while (index + 1 < a.n) {
        a.a[index] = a.a[index+1];
        index += 1;
    }
    a.n -= 1;
    return;
}

int main () {
    Array arr(2);

    read(arr);
    print(arr);
    append (arr, 55);
    pop(arr, arr.n-1);
    print(arr);
    
    cout << "\nExit Success.";
    return 0;
}