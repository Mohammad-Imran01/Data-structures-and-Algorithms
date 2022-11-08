#include <iostream>
using namespace std;

class queue{
private:
    int size;
    int f;
    int r;
    int *q;
public:
    queue(int length)
    : size { length }, f { 0 }, r { 0 }, q { new int [size] } { } 
    
    // pushes an element at the end;
    void push(int);
    // removes element at first;
    void pop();
    // print all element
    void print();
    // returns element at first;
    int front();
};

void queue::push (int val) {
    if((r+1)%size == f) return;
    q[(++r)%size] = val;
}
void queue::pop () {
    if(r == f) return;
    q[f] = 0;
    f = (f+1)%size;
}
int queue::front() {
    if(f == r) return -1;
    return q[f+1];
}
void queue::print() {

    int i = (f+1)%size;
    do {
        printf("%d ", q[i]);
        i = (i+1)%size;
    } while (i != (r+1)%size);
    
    cout << endl;
}

int main () {
    queue q(6);
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.push(7);

    q.print();

    return 0;
}