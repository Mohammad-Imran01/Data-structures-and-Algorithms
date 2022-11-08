#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(): data { 0 }, next { nullptr }, prev { nullptr } { }
    Node(int val, Node* n=nullptr, Node* p=nullptr)
    : data { val }, next { n }, prev { p } {}
};
class list {
private:
    Node* head;
public:
    list () : head { nullptr } {}
    list (int val, Node* n = nullptr, Node* p=nullptr)
    : head { new Node(val, n, p) } {}

    // prints all the data in the list
    void print(bool);
    // removes a node before head.... 
    void pop(int);
    // inserts a node before head.........
    void append(int);
    // reverse list
    void reverse();
    //returns middle node address
    Node* mid_node();
    // return adress where intersection starts
    Node* intersection(Node* );
    Node* get_head(){
        return head;
    }
};

void list::print(bool rev = false) {
    Node* p = head;
    if(!p) return;
    if(rev) {
        while (p->next) p = p->next;
        while(p) {
            cout << p->data << " ";
            p = p->prev;
        }
    } else {
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
    }
    cout << endl;
}
void list::append(int val=0) {
    if(!head) {
        head = new Node(val);
        head->next = head->prev = nullptr;
        return;
    } else {
        Node* p = head;
        while(p->next) p = p->next;
        p->next = new Node(val, nullptr, nullptr);
        p->next->prev = p;
        p->next->next = nullptr;
    }
}
void list::pop(int index=-1) {
    if(!head || !head->next) {
        head = head->prev = head->next = nullptr;
        return;
    }
    Node* p = head;

    if(index == -1) {
        while(p->next) p = p->next;
        p->prev->next = nullptr;
        delete p;
        return;
    } else {
        if(index == 1) {
            head = p->next;
            head->prev = nullptr;
            delete p;
            return;
        }
        while (p->next && index-- > 1) p = p->next;
        p->prev->next = p->next;
        if(p->next)
        p->next->prev = p->prev;
        delete p;
        return;
    }
}
void list::reverse() {
    if(!head || !head->next) return;
    Node* p = head;
    while (p) {
        swap(p->next, p->prev);
        
        if(!p->prev) head = p;
        p = p->prev;
    }
}
Node* list::intersection(Node* h2){
    Node* p = head;
    stack<Node*> s1;
    stack<Node*> s2;

    while(p) {
        s1.push(p);
        p = p->next;
    }
    p = h2;
    while(p) {
        s2.push(p);
        p = p->next;
    }
    while(s1.top() == s2.top()) {
        p = s1.top();
        s1.pop();
        s2.pop();
    }
    return p;    
}
Node* list::mid_node(){
    Node *p = head, *q = head;
    while(q && q->next) {
        p = p->next;
        q = q->next->next;
    }
    return p;
}


int main () {
    list a, b;

    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);

    b.append(13);

    Node* p = a.get_head();
    Node* q = b.get_head();

    q->next = p->next->next->next;

    cout << (a.intersection(q))->data << '\n';



    cout << "Exit success...";
    return 0;
}