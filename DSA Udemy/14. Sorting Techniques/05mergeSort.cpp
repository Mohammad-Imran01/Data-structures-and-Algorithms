#include <iostream>
using namespace std;

void merge (int a[], int l, int mid, int h) { 
    int c[h+1] { 0 };

    int i { l }, j { mid+1 }, k { l };

    while (i <= mid && j <= h) {
        if(a[i] < a[j]) c[k++] = a[i++];
        else c[k++] = a[j++];
    }
    for(; i <= mid; i++) c[k++] = a[i];
    for(; j <= h; j++)   c[k++] = a[j];

    for(i = l; i <= h; i++) a[i] = c[i];
}
void mergesort(int a[], int n) {
    int p, i, l, h, mid;

    for(p = 2; p <= n; p*=2) {
        for (i = 0; (i + p - 1) < n; i+=p) {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(a, l, mid, h);
        }
    }
    if(p/2 < n) merge (a, 0, (p/2)-1, n-1);
}

void print(int a[], int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main () {
    int a[]{ 3, 2, 1, 5, 4, 6, 7 };
    int m {sizeof(a)/sizeof(a[0])};

    mergesort(a, m);

    print(a, m);

    return 0;
}