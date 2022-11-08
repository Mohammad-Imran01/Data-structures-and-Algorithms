#include <iostream>
#include <limits.h>
using namespace std;
int partition2(int a[], int l, int h) {
    int pivot = a[l];
    int i { l }, j { h };

    while(i < j) {
        do{i++;} while(a[i] <= pivot);
        do{j--;} while(a[j] > pivot);
        if(i < j) swap (a[i], a[j]);
    }
    swap(a[l], a[j]);
    return j;
}
int quicksort2(int a[], int l, int h) {
    if(l < h) {
        int p = partition2(a, l, h);
        quicksort2(a, l, p);
        quicksort2(a, p+1, h);
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
    quicksort2(a, 0, n-1);

    print(a, n);


    return 0;
}