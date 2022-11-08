/*
(n sort gives n largest elements)
Its Stable and Adaptive
Max = O(n^2)
Min = O(n)
(n^2 - comparison)
(n^2 - swap)
(n-1  - pass)
*/ 
#include <iostream>
using namespace std;

// sorts elements in O(n^2) complx.. without changing same element position..
void bubblesort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int flag{};
        for(int j = 0; j < n-1-i; j++) {
            flag+=1;
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
        if(!flag) return;
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main () {
    int a[]{1, 2, 3, 4, 5, 3};
    int n{sizeof(a)/sizeof(a[0])};

    bubblesort(a, n);
    print(a, n);
    return 0;
}