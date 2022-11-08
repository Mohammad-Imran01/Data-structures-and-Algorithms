#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val)
    : data { val }, next { nullptr } { }
    Node()
    : data { 0 }, next { nullptr } { }
};
int digits(int a[], int n) {
    int max{ a[0] };
    for(int i = 1; i < n; i++) 
        if (a[i] > max) max = a[i];
    
    int times{};
    while(max){
        max/=10;
        times++;
    } 
    return times;
}
void radixSort(int a[], int n) {
    int times{ digits(a, n) }, j{};

    Node* *bucket = new Node*[10];
    for(int i = 0; i < 10; i++)
        bucket[i] = nullptr;
    int p = 1;
    while(times >= 0) {
        for (int i = 0; i < n; i++) {
            int index;
            index = abs((a[i]/p)%10);
            if(bucket [index] == nullptr)
                bucket[index] = new Node(a[i]);
            else {
                Node* p = bucket[index];
                while(p->next) p = p->next;
                p->next = new Node(a[i]);
            }
        }    
        for(int i = 0, j=0; i < 10; i++) {
            Node* p = bucket[i];
            while(p) {
                a[j++] = p->data;
                p = p->next;
            }
            delete p;
            bucket[i] = nullptr;
        }
        p*=10;
        times -= 1;
    }
}

void print(int a[], int n) {
    for(int i = 0 ; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
int main () {
    int a[] {3, 66, 125,435, 4, -1, 22, 32, 88, 179};
    int n { sizeof(a)/sizeof(a[0]) };
    radixSort(a, n);
    print(a, n);
    cout << "\n_____________________";
}