#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    // constructors
    Node(): data { 0 }, next { nullptr } {} 
    Node(int val, Node* n = nullptr)
    : data { val }, next { n } {}
};
class list{
private:
    Node* head;
public:
    list(): head { nullptr } {}
    list(int val, Node* n=nullptr) {
        head = new Node(val, n);
    }
    void print();
    void read ();
    /* index = 0 to insert at first index = -1 to insert at end */
    void insert(int val, int index);
    /* removes last node or Node at given index.... returns nothing 
        index starts 1 and -1 for last index(default) */
    void pop(int);
};

void list::print() {
    const Node* p=head;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p && p != head);
    cout << endl;
}
void list::insert(int val, int index= -1) {
    // if there is no node already
    if(!head) {
        head = new Node(val);
        head->next = head;
        return;
    }
    // insert at first or at end
    if(index < 1) {
        Node* p = head;
        do {
            p = p->next;
        } while (p && p->next != head);
        p->next = new Node(val);
        p->next->next = head;
        if(index == 0) head = p->next;
        return;
    }

    Node* p = head;
    while(p && index > 1) {
        p = p->next;
        index -= 1;
    }
    Node* q = new Node(val);
    q->next = p->next;
    p->next = q;
}
void list::pop (int index=-1) {
    if(!head || !index) return;
    Node* p = head, *tail = nullptr;
    if (index <= 1) {
        while(p && p->next != head) {
            tail = p;
            p = p->next; 
        }
        if(index == 1) {
            tail = p;
            p = p->next;
            tail->next = p->next;
            head = head->next;
            delete p;
            return;
        }
        tail->next = p->next;
        delete p;        
    } else {
        while (index > 1) {
            tail = p;
            p = p->next;
            index--;
        }
        tail->next = p->next;
        if(p == head) head = head->next;
        delete p;
    }
}

int main () {
    list h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.pop(0);
    h.print();

    cout <<"Exit success...";
}
