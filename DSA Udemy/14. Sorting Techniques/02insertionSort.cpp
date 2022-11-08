
/*
Adaptiveṇṇ
time = O(n) to O(n^2)
comparison (n^2 - )
swap = 1 - n^2 
*/
#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
    for(int i = 0; i < n-1; i++) {
        int j{i+1}, val = a[j];
        while(j > 0 && a[j-1] > val) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = val;
    }
}
void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

int main () {
    int a[]{1, 2, 3, 4, 5, 5, 1, 2, 3, 5, 4};
    int n{sizeof(a)/sizeof(a[0])};

    insertionSort(a, n);
    print(a, n);
    return 0;
}