#include <iostream>
#include <stack>
using namespace std;

/*queue using double stack*/

class queue{
private:
    stack<int> in;
    stack<int> out;
public:
    void push(int);
    void pop();
    int front();
};
void queue::push(int val) {
    in.push(val);
}
void queue::pop() {
    if(out.size()) {
        out.pop();
    } else {
        while(!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
    out.pop();
}
int queue::front() {
    if(!out.size()) {
        while(!in.empty()) {
            out.push(in.top());
            in.pop();
        }  
    }
    return out.top();
}

int main () {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(5);
    q.pop();
    cout << q.front();
}