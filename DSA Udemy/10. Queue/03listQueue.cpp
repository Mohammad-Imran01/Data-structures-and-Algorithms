#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next, *prev;
    Node(int v) {
        data = v;
        next = prev = nullptr;
    }
};

class queue {
private:
    Node* f, *r;
public:
    queue(): f { nullptr }, r { nullptr } { }
    
    // pushes an element at the end;
    void push(int);
    // removes element at first;
    void pop();
    // print all element
    void print();
    // returns element at first;
    int front();
};

void queue::push(int val) {
    if (!f) 
        f = r = new Node(val);
    else {
        r->next = new Node(val);
        r = r -> next;
    }
}
void queue::pop(){
    if(!f) return;
    if(f == r) {       
        delete f;
        f = r = nullptr;
    } else {
        f = f->next;
        delete f->prev;
        f->prev = nullptr;
    }
}
void queue::print(){
    if(!f) return;
    Node* p = f;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';
}
int queue::front(){
    if(!f) return -1;
    return f->data;
}


int main () {
    cout << "_____________\n";
    queue q;
    q.push(5);
    q.push(3);
    q.push(1);
    q.push(7);

    q.print();

    cout << "_____________";
}