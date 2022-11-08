#include <iostream>
using namespace std;

class queue{
private:
    int* q;
    int size;
    int f, r;
public:
    queue(int sz) {
        size = sz;
        f = r = -1;
        q = new int[size];
        for(int i = 0; i < size; i++) q[i] = 0;
    }
    void push(int val);
    void pop();
    int front();
    void print();
};

void queue::push(int val) {
    if(r < size-1) q[++r] = val;
}
int queue::front() {
    if(f == r) return -1;
    int ans{q[f+1]};
    for(int i = f+1; i <= r; i++) 
        ans = ans > q[i] ? ans:q[i];
    return ans;
}
void queue::pop() {
    if(f == r) return;
    int j = f+1;
    for(int i = j; i <= r; i++)
    j = q[i] > q[j] ? i:j;

    while(j <= r) {
        q[j] = q[j+1];
        j++;
    }
    --r;
}
void queue::print() {
    for(int i = f+1; i <= r; i++) 
        cout << q[i] << ' ';
    cout << endl;
}

int main () {
    queue q(5);
    q.push(9);
    q.push(1);
    q.push(7);
    q.push(2);
    q.push(3);

    while (q.front() != -1) {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}