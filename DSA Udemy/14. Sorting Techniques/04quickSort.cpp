#include <iostream>
using namespace std;

int party (int a[], int l, int h) {
    int piv { a[l] };
    int i { l }, j { h };

    do {
        do { i++; } while (a[i] <= piv);
        do { j--; } while (a[j] > piv);

        if(i < j) swap (a[i], a[j]);
    } while (i < j);
    swap (a[l], a[j]);

    return j;
}
void quicksort (int a[], int l, int h) {
    if (l < h) {
        int p = party (a, l, h);
        quicksort(a, l, p);
        quicksort(a, p+1, h);
    }
}

void print(int a[], int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main () {
    int a[]{ 2, 5, 4, 6, 1, 3 };
    int n{sizeof(a)/sizeof(a[0])};
    quicksort(a, 0, n);
    print(a, n);

    return 0;
}