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
// recursive print
void print2(const Node* head) {
    if(head) {
        cout << head->data << " ";
        print2(head->next);
    } else {
        cout << endl;
        return;
    }
    
}

Node* rev(Node* head) {
    if(!head || !head->next) return head;
    Node* p = rev(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p                      ;

}
Node* reverse(Node* head) {
    Node* prev, *curr=nullptr;
    while(head) {
        prev = head->next;
        head->next = curr;
        curr = head;
        head = prev;
    }
    return curr;
}


int main () {
    Node* t =nullptr;
    insert(&t,1,-1);
    insert(&t,2,-1);
    t = rev (t);
    print2(t);
}