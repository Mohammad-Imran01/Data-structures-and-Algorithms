#include <iostream>
using namespace std;

class stack{
private:
    int size;
    int last;
    int* s;
public:
    stack(int capacity, int topp = -1) {
        size = capacity;
        last = topp;
        s = new int[capacity];
        for(int i = 0; i < size; i++) s[i] = 0;
        
    }
    // pushes given element at stack top
    void push(int val);
    // removes top element.. No data is returned..
    void pop();
    // returns topmost element
    int top();
    /* returns element at given 
    index if index isn't valid returns -1*/
    int peek(int index);
    // returns true if stack is full else false
    int full();
    // returns true if stack is empty else returns false
    int empty();

    friend void print(stack s);
    
};
void print(stack s){
    for(int i = s.last; i >= 0; i--) {
        cout << s.peek(i+1) << " ";
    }
    cout << endl;
}
void stack::push(int val){
    if(full()) return;
    s[++last] = val;
}
void stack::pop(){
    if(empty()) return;
    s[last--] = 0; 
}
int stack::top(){
    if(empty()) return -1;
    return s[last];
}
int stack::peek(int index){
    if(empty() || index > last+1)
        return -1;
    return s[last - (index-1)];
}
int stack::full(){
    return (last == size-1);
}
int stack::empty(){
    return last < 0;
}


int main () {           
    cout << "\nWelcome, Chief...\n";
    stack s(5);
    s.push(55);
    s.push(44);
    s.push(33);
    s.push(22);
    s.push(11);

    print(s);
    cout << s.top() << endl;

    cout <<"Exit success...\n" << endl;;
    return 0;
}