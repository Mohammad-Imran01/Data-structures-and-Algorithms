#include <iostream>
#include <algorithm>
#define size 100
using namespace std;

//A structure consisting of an dynamic array and n - (no of elements present)
struct Array {  
    int *a = new int[size];
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
// Searches for the given key, Returns its index if found else returns -1...
int lin_search (Array a, int key) {
    int i{};
    while (i < a.n) {
        if(a.a[i] == key) return i;
        i++;
    }
    return -1;
}
//// Searches for the given key in SORTED ARRAY, Returns its index if found else returns -1...
int binSearch (Array a, int val) {
    sort (a.a, a.a + a.n);

    int low{}, high{a.n-1};

    while (high >= low) {
        int mid{(low+high)/2};
        
        if(a.a[mid] == val) 
            return mid;
        else if (val > a.a[mid]) 
            low = mid + 1;
        else 
            high = mid-1;
    }
    return -1;
}
//// Search Recursively for the given key in SORTED ARRAY, Returns its index if found else returns -1...
int binsearch (Array a, int key, int low, int high) {
    if (low > high) return -1;
    int mid { (low+high)/2 };
    if (a.a[mid] == key) return mid;
    else if (key > a.a[mid])
        return binsearch(a, key, mid+1, high);
    else
        return binsearch(a, key, low, mid-1);
}
int binsearchII (Array a, int key) {
    return binsearch (a, key, 0, a.n-1);
}
//Returns index with max element;
int max (Array a) {
    int ans{a.n-1};
    for (int i = 0; i < a.n; i++)
        ans = a.a[ans] > a.a[i] ? ans:i;
    return ans;
}
int average (Array a) {
    int avg{ };
    for (int i = 0; i < a.n; i++)
        avg += a.a[i];
    return avg/a.n;
}

int main () {
    Array arr(3);
    read(arr);
    cout<< average (arr);

    cout << "\nExit Success.";
    return 0;
}