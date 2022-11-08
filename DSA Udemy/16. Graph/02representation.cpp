#include <iostream>
#define size 5
using namespace std;

struct Node{
    int val; 
    Node* next;
    Node(int v) : val { v }, next { nullptr } { }
    Node(): val { 0 }, next { nullptr } { }
};

void insert(Node* g, int to) {
    while(g->next && g->next->val < to) g = g->next;
    Node* q = g->next;
    g->next = new Node(to);
    g->next->next = q;
    q = g = nullptr;
}
void print(Node** g) {
}

void create() {
    Node** g = new Node*[size];
    

}

int main () {

}