// stack using linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val, Node* after=nullptr, Node* before=nullptr)
    : data { val }, next { after }, prev { before } { }
};

class stack {
private:
    Node* top;
public:
    stack()
    : top { nullptr } { }

    // push an element to the top;
    void push(int val);
    // removes last elements... returns nothing;
    void pop();
    // returns top element;
    int get_top();
    // prints all element;
    void print();
    // takes input and pushes one by one all of them
    void read();

};

void stack::push (int val) {
    if(!top) {
        top = new Node(val);
        top->prev = top->next = nullptr;
        return;
    } else {
        top->next = new Node(val);
        top->next->prev = top;
        top = top->next;
        top->next = nullptr;
        return;
    }
}
void stack::print () {
    if(!top) return;
    Node* p = top;
    while(p) {
        cout << p->data << ' ';
        p = p->prev;
    }
    cout << endl;
    return;
}
void stack::pop () {
    if(! top -> prev) {
        delete top;
        top = nullptr;
    } else {
        top = top->prev;
        delete top->next;
        top->next = nullptr;
    }
}
int stack::get_top () {
    if(top) return top->data;
    return -1;
}



int main () {
    stack s;
    s.push(1);
    s.pop();
    s.push(1);
    cout << s.get_top();

    cout << endl;
}