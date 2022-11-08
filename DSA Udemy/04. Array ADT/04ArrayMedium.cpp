#include <iostream>
#include <algorithm>
#define size 100
using namespace std;

//A structure consisting of an Array and n - (no of elements present)
struct Array {  
    int *a = new int[size]{};
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
//reverse all elements of the Array
void reverse (Array a) {
    for(int i = 0, j = a.n-1; i < j; i++, j--) {
        swap(a.a[i], a.a[j]);
    }
    return;
}
/* Shift elements of the Array, Positive parameter means towards right
negative means towards left*/
void shift (Array a, int times) {
    if (a.n < 2 || times == 0) return;

    int temp {}, i{};
    if (times < 0) { // left -neg
        while (times++) {
            temp = a.a[0];
            for (i = 1; i < a.n; i++) 
                a.a[i-1] = a.a[i];
            a.a[a.n-1] = temp;
        }        
    } else { // right +pos
        while (times--) {
            temp = a.a[a.n-1];
            for (i = a.n-1; i > 0; i--) 
                a.a[i] = a.a[i-1];
            a.a[i] = temp;
        }
    }
    return;
}
//Returns true if Array is sorted
bool sorted (Array arr) {
    for (int i = 1; i < arr.n; i++) 
        if (arr.a[i] < arr.a[i-1])
            return false;
    return true;
}
// Merges two Unsorted Array into a new one  
void merge (Array& a, Array& b) {
    int i{}, j{}, k{};
    if (!sorted (a) || !sorted(b)) {
        for (i = a.n, j = 0; i < size && j < b.n; i++, j++) {
            a.a[i] = b.a[j];
        }
        a.n += b.n;
        return;
    }
    int* c = new int[size]{};
    
    while ((i < a.n && j < b.n) && k < size) {
        if (a.a[i] == b.a[j]) {
            c[k] = a.a[i];
            i++, j++;
        } else {
            if (a.a[i] < b.a[j]) {
                c[k] = a.a[i];
                i++;
            } else {
                c[k] = b.a[j];
                j++;
            }
        }
        k++;
    }
    while(i < a.n)
        c[k++] = a.a[i++];
    while(j < b.n)
        c[k++] = b.a[j++];

    delete[] a.a;
    a.a = nullptr;
    a.a = c;
    c = nullptr;
    a.n = k;

}

int main () {
    Array arr (3), a(4);
    read (arr);
    read (a);
    merge (arr, a);
    print (arr);

    return 0;
}