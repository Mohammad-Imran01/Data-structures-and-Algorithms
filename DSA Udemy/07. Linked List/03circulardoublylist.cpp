#include <iostream>
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
    list () : head {  } {}
    list (int val, Node* n = nullptr, Node* p=nullptr)
    : head { new Node(val, n, p) } {}

    // prints all the data in the list
    void print(bool);
    // removes a node before head.... 
    void pop(int);
    // inserts a node before head.........
    void append(int);
};
void list::print(bool reverse = false) {
    if(!head) return;
    if(reverse) {
        head = head -> prev;
        Node* p = head;
        do {
            cout << p->data << " ";
            p = p -> prev;
        } while (p && p != head);
        head = head->next;
    } else {
        Node* p = head;
        do {
            cout << p->data << ' ';
            p = p->next;
        } while (p && p!= head);
    }
    cout << endl;
}
void list::append(int val=0) {
    if(!head) {
        head = new Node(val);
        head->next = head->prev = head;
        return;
    } else {
        Node* p = new Node(val);

        p->prev = head->prev;
        p->next = head;

        head -> prev -> next = p;        
        head -> prev = p;
    }
}
void list::pop(int index=-1) {
    if(!head) return;
    // removing last node 
    Node* p = head;
    if (index == -1) p = p->prev;
    else  while (index-- > 1) p = p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;

    if(p == head) {
        head = head->next;
        if(p == head) {
            delete p;
            head = nullptr;
        }
        else delete p;
    }
}


int main () {
    cout <<"Hello, Chief...\n";
    list l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);

    l.pop();

    l.print();
    l.print(1);

    cout <<"Exit success...";
}