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
int maxelement(int a[], int n) {
    if(!n) return n;
    int ans{a[0]};
    for(int i = 0; i < n; i++)
        if ( a[i] > ans ) ans = a[i];
    return ans;
}
void binSort(int a[], int n) {
    int max { maxelement(a, n)+1 };
    Node** bucket = new Node*[max];
    for(int i = 0; i < max; i++) bucket[i] = nullptr;

    for(int i = 0; i < n; i++) {
        if(!bucket[a[i]])bucket[a[i]] = new Node(a[i]);
        else {
            Node* p = bucket[a[i]];
            while(p->next) p = p->next;
            p->next = new Node(a[i]);
        }
    }
    int j = 0;
    for(int i = 0; i < max; i++) {
        Node* p = bucket[i];
        while(p) {
            a[j++] = p->data;
            p = p->next;
        }           
        delete bucket[i];
        bucket[i] = nullptr; 
    }
}

void print(int a[], int n) {
    for(int i = 0 ; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
int main () {
    int a[] {3, 66, 5, 1, 22};
    binSort(a, 5);
    print(a, 5);

    cout << "\n_____________________";
}