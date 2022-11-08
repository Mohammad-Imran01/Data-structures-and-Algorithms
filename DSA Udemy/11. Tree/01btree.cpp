#include <queue>
#include <stack>
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left, *right;
    Node(int val)
    : data { val }, left { nullptr }, right { nullptr } { }
};

class tree{
private:
    Node* root;
public:
    tree(): root { nullptr } {}
    tree(int val)
    : root { new Node(val) } { }

    void create();
    Node* &get_root() { return root; } 
};

void tree::create () {
    int x{};
    cout << "Enter root val: " ;
    cin >> x;

    root = new Node(x);

    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* p = q.front();q.pop();
        cout << "Enter a val for: " << p->data << "'s left: " ;
        cin >> x;    
        if(x != -1) {
            p->left = new Node(x);
            q.push(p->left);
        }

        cout << "Enter a val for: " << p->data << "'s right: " ;
        cin >> x;    
        if(x != -1) {
            p->right = new Node(x);
            q.push(p->right);
        }
    }
}
void preorder(Node* p) {
    if (p) {
        cout << p->data << ' ';
        preorder (p->left);
        preorder (p->right);
    }
}
void inorder(Node* p) {
    if (p) {
        inorder (p->left);
        cout << p->data << ' ';
        inorder (p->right);
    }
}
void postorder(Node* p) {
    if (p) {
        postorder (p->left);
        postorder (p->right);
        cout << p->data << ' ';
    }
}
int searchInorder(int inArray[], 
    int inStart, int inEnd, int data) {
    for (int i=inStart; i<=inEnd; i++){
        if (inArray[i] == data){
            return i;
        }
    }
    return -1;
}

Node* fromTraversal (int* in, int* pre, 
    int instart, int inend)                 {

    static int preindex{ 0 };
    
    if (instart > inend) return nullptr;
    Node* n = new Node(pre[preindex++]);

    if ( instart == inend ) return n;

    int mid = searchInorder(in, instart, inend, n->data);
    n -> left = fromTraversal(in, pre, instart, mid-1);
    n -> right = fromTraversal(in, pre, mid+1, inend);

    return n;
}


int main () {
    tree t;

    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    t.get_root() = fromTraversal(inorder, preorder, 0, 
        sizeof(inorder)/sizeof(inorder[0]) - 1
    );
    postorder(t.get_root());

    return 0;
}