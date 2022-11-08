#include <iostream>
#include <math.h>
using namespace std;

class Node{
public:
    int ceoff;
    int pow;
    Node* next;

    Node() : ceoff {}, pow {}, next { } {}

    Node(int ce, int po, Node* nex=nullptr) {
        ceoff = ce;
        pow = po;
        next = nex;
    }
};
class poly{
private:
    Node* exp;
public:
    poly(): exp { nullptr } {}
    poly(int ce, int po, Node* nex=nullptr) {
        exp = new Node(ce, po, nex);
    }
    void read();
    void print();
    void append(int ceof, int power);
    double evaluate(int);
};
void poly::append(int ceof, int power) {
    if(!exp) {
        exp = new Node(ceof, power);
        return;
    } else {
        Node* p = exp;
        while(p->next) p = p->next;
        p->next = new Node(ceof, power);
        return;
    }
}
void poly::read() {
    int ceof, po;
    cout << "Enter 'ceoff pow': \n";
    while ((cin >> ceof >> po)) {
        append(ceof, po);
    }
    return;
}
void poly::print(){
    Node* p = exp;
    while(p){
        cout<< p->ceoff<<"x^"<<p->pow;
        if(p->next) cout <<" + ";
        p = p->next;
    }
}
double poly::evaluate(int x){
    double ans{0.0};
    Node* p = exp;
    while(p) {
        ans += p->ceoff* pow(x, p->pow);
        p = p->next;
    }
    return ans;
}
int main () {
    poly p;
    p.read();
    p.print();
    cout << endl << p.evaluate(2);
    return 0;

}