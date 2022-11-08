// Intersection union difference
#include <iostream>
#define size 100
using namespace std;

//A structure consisting of an Array and n - (no of elements present)
struct Array {  
    int *a;
    int n;

    Array(int elements) {
        a = new int[size];
        n = elements;
        for(int i = 0; i < size; i++)
            a[i] = 0;
    }
    Array() {
        a = new int[size];
        n = 0;
        for(int i = 0; i < size; i++)
            a[i] = 0;
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
    if (!a.n) {
        cout << "\nFound no elements..\n";
        return;
    }
    cout << "\nElements are: ";
    for(int i = 0; i < a.n; i++)
        cout << a.a[i] << ' ';
    cout << '\n';
    return;
}
//Returns true if Array is sorted
bool sorted (Array arr) {
    for (int i = 1; i < arr.n; i++) 
        if (arr.a[i] < arr.a[i-1])
            return false;
    return true;
}
/// Takes two array makes first array union of two..
void get_union (Array& A, Array& B) {
    int i{}, j{}, k{};
    if(!sorted(A) || !sorted(B)) {
        k = A.n;
        for(i = 0; i < B.n; i++) {
            for (j = 0; j < A.n; j++) {
                if (B.a[i] == A.a[j]) break;
            }
            if (j == A.n) A.a[A.n++] = B.a[i];
        }
        return;
    }   
    
    int* c = new int[size]{};
    
    while ((i < A.n && j < B.n) && k < size) {
        if (A.a[i] == B.a[j]) {
            c[k] = A.a[i];
            i++, j++;
        } else {
            if (A.a[i] < B.a[j]) {
                c[k] = A.a[i];
                i++;
            } else {
                c[k] = B.a[j];
                j++;
            }
        }
        k++;
    }
    while(i < A.n)
        c[k++] = A.a[i++];
    while(j < B.n)
        c[k++] = B.a[j++];

    delete[] A.a;
    A.a = nullptr;
    A.a = c;
    c = nullptr;
    A.n = k;
}

/*Makes first Array Difference of Two Array 
i.e Elements of first array not in second..*/
void difference (Array& a, Array &b) {
    int i{}, j{}, k{};
    Array ans(10);

    for(i = 0 ; i < a.n; i++) {
        for (j = 0; j < b.n; j++) {
            if (b.a[j] == -1) continue;
            if (a.a[i] == b.a[j]) break;;
        }
        if (j == b.n) {
            ans.a[k++] = a.a[i];
        }
    }
    delete[] a.a;
    a.a = nullptr;
    a.a = ans.a;
    ans.a = nullptr;
    a.n = k;    
}

/*Makes first Array Intersection of Two Array 
i.e Elements of first array and element of second Array..*/
void intersection (Array &a, Array &b) {
    int i{}, j{}, k{};
    Array c(size);
    for (i = 0; i < a.n; i++) {
        for (j = 0; j < b.n; j++) {
            if (a.a[i] == b.a[j]) {
                c.a[k++] = a.a[i];
            }
        }
    }
    delete[] a.a;
    a.a = nullptr;
    a.a = c.a;
    c.a = nullptr;
    a.n = k;
}


int main () {
    Array a(3), b(3);

    read (a), read (b);
    intersection (a, b);
    print (a);

    return  0;

}