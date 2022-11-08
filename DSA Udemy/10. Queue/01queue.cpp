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
    : size { length }, f { -1 }, r { -1 }, q { new int [size] } { } 
    
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
    if(r == size-1) return;
    q[++r] = val;
}
void queue::pop(){
    if(f == r) return;
    ++f;
}
int queue::front() {
    if(f == -1 || f == size-1) return -1;
    return q[f+1];
}
void queue::print() {
    for(int i = f+1; i <= r; i++) 
        cout << q[i] << " ";
    cout << endl;
}

int main () {
    queue q(5);
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.print();

    return 0;
}