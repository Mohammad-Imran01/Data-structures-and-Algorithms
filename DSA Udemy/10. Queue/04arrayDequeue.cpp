#include <iostream>
using namespace std;

class dequeue  {
private:
    int size;
    int f;
    int r;
    int *q;
public:
    dequeue
    (int length)
    : size { length }, f { -1 }, r { -1 }, q { new int [size] } { } 
    
    // pushes an element at the end;
    void push(int);
    // removes element at first;
    void pop_front();
    // print all element
    void print();
    // returns element at first;
    int front();
    // pop back
    void pop_back();
    // returns element at end;
    int rear();
};

void dequeue::push(int val) {
    if(r == size-1) return;
    q[++r] = val;
}
void dequeue::pop_front(){
    if(f == r) return;
    ++f;
}
int dequeue::front() {
    if(f == -1 || f == size-1) return -1;
    return q[f+1];
}
void dequeue::print() {
    for(int i = f+1; i <= r; i++) 
        cout << q[i] << " ";
    cout << endl;
}
void dequeue::pop_back() {
    if(r == -1 || r == f) 
        return;
    --r;
}
int dequeue::rear() {
    if(r > f) return q[r];
}


int main () {


    return 0;
}