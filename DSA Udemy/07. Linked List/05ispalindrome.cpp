#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val)
    : data {val}, next { nullptr } { }
    Node()
    : data { 0 }, next { nullptr } { }
};

Node* insert(Node **head_ref, int val = -1, int after=0) {
    if(*head_ref == nullptr || after == 0) {
        auto x = new Node(val);
        x->next = *head_ref;
        *head_ref = x;
        return *head_ref;
    } else {
        Node* p = *head_ref, *tail = nullptr;
        while (p->next && --after) {
            p = p->next;
        }
        auto new_node = new Node(val);
        new_node->next = p->next;
        p->next = new_node; 
    }
    return *head_ref;
}
void print2(const Node* head) {
    if(head) {
        cout << head->data << " ";
        print2(head->next);
    } else {
        cout << endl;
        return;
    }    
}
Node* reverse(Node* h) {
    if(!h || !h->next) return h;
    Node* p = reverse(h->next);
    h->next->next = h;
    h->next = nullptr;
    return p;
}
bool ispalindrome(Node* h) {
    if(!h) return false;
    if(!h->next) return true;
    Node* s = h, *f = h;
        while(f && f->next) {
            f = f->next->next;
            s = s->next;
        }
        f = h;
        s = reverse(s);

    while(f && s) {
        if(f->data != s->data) return false;
        f = f->next;
        s = s->next;
    }
    return true;
}

int main (){
    Node* p = nullptr;
    insert(&p, 1, -1);
    insert(&p, 2, -1);
    // insert(&p, 2 -1);

    // cout << ispalindrome(p);
    cout << 10/10;

    //    print2(p);
}