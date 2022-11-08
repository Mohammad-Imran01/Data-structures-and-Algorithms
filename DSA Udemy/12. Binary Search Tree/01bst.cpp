#include <stack>
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
void _preorder(Node* h) {
    stack <Node*> s;
    s.push(h);
    Node* p;

    while(!s.empty() ) {
        p = s.top(); s.pop();
        cout << p->data << ' ';
        if(p->right) s.push(p->right);
        if (p->left) s.push(p->left);
    }
    cout << endl;

}
void _inorder(Node* h) {
    if (!h) return;
    stack <Node*> s;

    while(!s.empty() || h) {
        while(h) {
            s.push(h);
            h = h->left;
        }
        h = s.top(); s.pop();
        cout << h->data << ' ';

        h = h->right;
    }
    cout << endl;
} 
void _postorder(Node* h) {
    stack <Node*> s;
    while(!s.empty() || h) {
        while (h) {
            if(h->right)
                s.push(h->right);
            s.push(h);
            h = h->left;
        }
        h = s.top(); s.pop();
        if(h->right && s.top() == h->right){
            s.pop();
            s.push(h);
            h = h->right;
        } else {
            cout << h->data << ' ';
            h = nullptr;
        }
    }
    cout << endl;
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
Node* insert(Node* root, int val) {
    if(root == nullptr) {
        return new Node(val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    } else if (val < root->data){
        root->left = insert(root->left, val);
    }
    return root;
}
Node* create (Node** root) {
    int val{1};
    cout << "enter values to insert: ";
    while((cin >> val)) {
        *root = insert (*root, val);
    } 
    return *root;
}
bool search(Node* h, int val) {
    if(!h) return false;
    if(h->data == val) return true;
    else if(val < h->data) {
        return search(h->left, val);
    } else {
        return search(h->right, val);
    }
}
int height (Node* h) {
    if(!h) return 0;
    return height (h->left) > height (h->right) ? height (h->left) + 1: height(h->right) + 1;
}
Node* successor(Node* h, bool left = true) {
    if(!h || (!h->left && !h->right)) return h;
    if(left) {
        if(!h->left) return h;
        h = h->left;
        while(h->right) h = h->right;
        return h;
    } else {
        if(!h->right) return h;
        h = h->right;
        while(h->left) h = h->left;
        return h;
    }
}

Node* remove(Node* head, int val) {
    if(head == nullptr) {
        return head;
    } else if(head->data == val && (head->left == nullptr && head->right == nullptr)) {
        head = nullptr;
        return head;
    } else if(val > head->data) {
        head->right = remove(head->right, val);
    } else if (val < head->data) {
        head->left = remove(head->left, val);
    } else {
        Node* p = nullptr;
        if(height(head->left) > height(head->right)) {
            p = successor(head);   
            head->data = p->data;
            head->left = remove(head->left, head->data);         
        } else {
            p = successor(head, false);
            head->data = p->data;
            head->right = remove(head->right, head->data);
        }
    }
    return head;
}
Node* bst_of_preorder(Node* head, int pre[], int n) {
    for(int i = 0; i < n; i++) {
        head = insert(head, pre [i]);
    }
    return head;
}

int main () {
    cout << " ________________________\n|________________________|\n\n";
    Node* head{ nullptr };
    // head = insert (head, 10);
    // head = insert (head, 8);
    // head = insert (head, 3);
    // head = insert (head, 5);
    // head = insert (head, 2);
    // head = insert (head, 12);

    int a[] { 10, 8, 2, 3, 12, 11, 15 };
    int n { sizeof(a)/sizeof(a[0]) };

    head = bst_of_preorder(head, a, n);

    preorder(head);

    cout << "\n ________________________\n|________________________|\n";
}
