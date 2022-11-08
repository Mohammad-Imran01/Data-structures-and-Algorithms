/*
Takes O(n) compl..
Auxuliary space of max element.
*/ 

#include <iostream>
using namespace std;

int max_num (int a[], int n) {
    if(!n) return n;

    int max{ a[0] };
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

void countSort(int a[], int n) {
    int max { max_num (a, n)+1 };
    int *c = new int[ max ];

    for(int i = 0; i < max; i++) c[i] = 0;

    for(int i = 0; i < n; i++) c[a[i]]++;

    int i = 0, j = 0;
    
    while(i < max) {
        while (c[i]) {
            a[j++] = i;
            c[i]--;
        }
        i++;
    }
}

void print(int a[], int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main () {
    int a[]{ 10, 3, 2, 1, 5, 4, 6 };
    int m {sizeof(a)/sizeof(a[0])};

    countSort(a, m);

    print(a, m);

    cout << "\n________________________";

    return 0;
}