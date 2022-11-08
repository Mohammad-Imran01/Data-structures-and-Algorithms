#include <iostream>
using namespace std;

struct Node {
    Node* next;
    int data;
    Node(int val)
    : data { val }, next { nullptr } {}
    Node()
    : data { 0 }, next { nullptr } { } 
};
void insert (Node* hash[], int val) {
    Node* p;
    if(val < 0) p = hash[10];
    else p = hash[abs(val)%10];
    if(!p->next) {
        p->next = new Node(val);
        return;
    } else {
        while ( p->next && p->next->data < val) {
            p = p->next;
        }
        Node* q = p->next;
        p->next = new Node(val);
        p->next->next = q;
        q = p = nullptr;
        return;        
    }
}
int search (Node* hash[], int val) {
    Node* p;
    if(val < 0) p = hash[10];
    else p = hash[abs(val)%10];

    p = p->next;
    while (p && p->data <= val) {
        if(p->data == val) //cout << p->data << ' ';
        return 1;
        p = p->next; 
    }
    return 0;
}
void print(Node** hash) {

    for(int i = 0; i <= 10; i++) {
        Node* p = hash[i];
        do {
            p = p->next;
            if(p) cout << p->data << ' ';
        } while (p);        
    }
    cout << endl;
}

int main () { cout << " ______\n|______|\n";
    Node* hash[11]; 
    for(int i = 0; i <= 10; i++) hash[i] = new Node;

    insert(hash, 4);
    insert(hash, 3);
    insert(hash, 6);
    insert(hash, 22);
    insert(hash, 31);
    insert(hash, 34);
    insert(hash, -24);
    insert(hash, 10);
    insert(hash, -10);
    // print(hash);
    cout << search (hash, 22);

    cout << "______\n|______|\n";
    return 0;
}