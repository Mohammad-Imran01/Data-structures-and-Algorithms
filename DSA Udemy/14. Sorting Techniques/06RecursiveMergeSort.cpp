#include <iostream>
using namespace std;

void merge (int a[], int l, int mid, int h) {
    int b[h+1] {0};
    int i{ l }, j { mid+1 }, k { l };

    while (i <= mid && j <= h) {
        if(a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    for(; i <= mid; i++) b[k++] = a[i];
    for(; j <= h; j++) b[k++] = a[j];
    for(i = l; i <= h; i++) a[i] = b[i];
}
void help(int a[], int l, int h) {
    if( l < h) {
        int mid = (l+h)/2;
        help (a, l, mid);
        help (a, mid+1, h);
        merge(a, l, mid, h);
    }
}
void mergeSort (int a[], int n) {
    help(a, 0, n-1);
}

void print(int a[], int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main () {
    int a[]{ 10, -9, 3, 2, 1, 5, 4, 6, 7 };
    int m {sizeof(a)/sizeof(a[0])};

    mergeSort(a, m);

    print(a, m);

    return 0;
}