/*
Not Adative. i.e sorted or unsorted O(n^2)
Not Stable.  i.e change position of same element
Min swaps it does. ie: n swpas
K passes gives K useful elements 
*/ 
#include <iostream>
#include <limits.h>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int j, k;
        for (j = k = i; j < n; j++) {
            if(a[j] < a[k]) k = j;
        }
        swap(a[k], a[i]);
    }
}
void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main () {
    int a[]{1, 2, 3, 4, 5, 5, 1, 2, 3, 5, 4, -1, 100};
    int n{sizeof(a)/sizeof(a[0])};
    selectionSort(a, n);

    // print(a, n);


    return 0;
}