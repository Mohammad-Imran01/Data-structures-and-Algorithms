#include <iostream>
#include <stack>
using namespace std;

// A struct of a value and pointer to next node
class Node {
public:
    int data;
    Node* next;

    Node ()
    : data{ }, next { nullptr } { }

    Node (int val, Node* after=nullptr) {
        data = val;
        next = nullptr;
    }
};

//return true if sorted else false
bool sorted(Node* head) {
    if(!head || !head->next)
        return true;
    while (head->next) {
        if (head->next->data < head->data) 
            return false;
        head = head->next;
    }
    return true;
}
// inserts a node with value in the end
void append (Node** head_ref, int val = 0) {
    if((*head_ref)) {
        Node* p = *head_ref;
        while (p->next) p = p->next;
        p->next = new Node(val);
    } else {
        *head_ref = new Node(val);
    }
}
// takes input to insert
void read (Node** head_ref) {
    int x;
    cout << "Insert values: ";
    /*takes input until gets EOF ex: @, # ! $*/
    while ((cin >> x)) append(head_ref, x);
}
// view elements of the list using loop
void print(const Node* head) {
    const Node* p=head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// recursive print
void print2(const Node* head) {
    if(head) {
        cout << head->data << " ";
        print2(head->next);
    } else {
        cout << endl;
        return;
    }
    
}
// returns total numbers of nodes
int count (Node* head) {
    if(head) {
        return count (head->next) + 1;
    } else {
        return 0;
    }
}
// returns sum of total elements
int sum (Node* head) {
    if(head) {
        return sum (head->next) + head->data;
    } else {
        return 0;
    }
}
// returns maximum elements
int max (Node* head) {
    if (!head) return 0;
    int max{head->data};
    Node* p = head;
    while (p) {
        max = max > p->data ? max:p->data;
        p = p->next;
    }
    return max;
}
// returns node which contains the given key, takes a paramaeter transfer: 
    // if true then the node will be brought to the first
Node* search(Node** head_ref, int key, bool transfer = false) {
    if (!(*head_ref)) 
        return nullptr;
    else if((*head_ref)->data == key) 
        return *head_ref;

    Node *p = *head_ref, *tail = nullptr;
    while (p && p->data != key) {
        tail = p;
        p = p->next;
    }     
    if(!p) 
        return *head_ref;
    
    if(transfer) {
        tail->next = p->next;
        p->next = (*head_ref);
        head_ref = &p;
    } else {
        return p;
    }    
    return (*head_ref);
}
//insert val after given key, if key not given then inserts before head
Node* insert(Node **head_ref, int val = -1, int after=0) {
    if(*head_ref == nullptr || after == 0) {
        auto x = new Node(val);
        x->next = *head_ref;
        *head_ref = x;
        return *head_ref;
    } else {
        Node* p = *head_ref, *tail = nullptr;
        while (p->next && --after) {
            p = p->next;
        }
        auto new_node = new Node(val);
        new_node->next = p->next;
        p->next = new_node; 
    }
    return *head_ref;
} 
//insert at sorted position, list must be sorted
Node* sorted_insert (Node* head, int val) {
    if(!sorted(head) || !head || head->data > val) {
        return insert(&head, val);
    }
    Node* p = head;
    while (p->next && p->next->data < val) p = p->next;

    auto new_node = new Node(val);
    new_node->next = p->next;
    p->next = new_node;

    return head;
}
// if given key found returns it's 1 based position, else returns 0...
int get_index(Node* head, int val) {
    if(!head) return 0;
    Node* p = head;
    int i;
    for(i = 1; p != nullptr; p = p->next, i++)
        if (val == p->data)
            return i;
    return 0;
}
// return val at position but returns -1 if position is invalid..
int get_val(Node* head, int posi) {
    if(!head || posi < 1) return 0;
    Node* p = head;

    while(p) {
       if(posi == 1) return p->data; 
       p = p->next;
       posi--;
    }
    return 0;
}
// Removes the Node of given value
Node* remove_val (Node* head, int val) {
    int index = get_index(head, val);
    
    if(!index) return head;
    else if (index == 1) {
        Node* q = head;
        head = head->next;
        delete q;
        return head;
    }

    Node* p = head;
    while(index > 2) {
        p = p->next;
        index--;
    }
    Node* q = p->next;
    p->next = p->next->next;
    delete q;
    return head;
} 
// Removes the Node of given position
Node* remove_index (Node* head, int posi) {
    int val = get_val(head, posi);
    return remove_val(head, val);
}
// removes duplicates from sorted list
Node* to_unique(Node **head) {
    Node* p = *head;
    while (p && p->next) {
        while(p && p->next && p->data == p->next->data) { 
            Node* q = p->next;
            p->next = p->next->next;
            delete q;
        }
        p = p->next;
    }
    return *head;
}
// reverse linked list using 2 pointer
Node* reverse(Node* head) {
    Node* curr = nullptr;
    while(head) {
        Node* next = head->next;
        head->next = curr;
        curr = head;
        head = next;
    }
    return curr;
}
// recursive reverse
Node* reverse (Node* pre, Node* curr) {
    if (curr) {
        auto head = reverse (curr, curr->next);
        curr->next = pre;
        return head;
    } else {
        return pre;
    }
}
// reverse using stack
Node* reversestk(Node* head) {
    stack<Node*> s;
    Node* p = head->next;

    while (head && p) {
        s.push(head);
        head->next = nullptr;
        head = p;
        p = p->next;
    }
    p = head;
    while(!s.empty()) {
        p->next = s.top(); s.pop();
        p = p->next;
    }
    return head;
}
// concate 2 list
Node* concat (Node* a, Node* b) {
    Node* p = a;
    while(p->next) p = p->next;
    p->next = b;
    return a;
}
// merge two sorted list
Node* merge (Node* a, Node* b) {
    Node* dum = new Node(0), *t = dum;
    while(a && b) {        
        if(a->data < b->data) {
            t->next = a;
            a = a->next;
        } else {
            t->next = b;
            b = b->next;
        }
        t = t->next;
    }
    
    if(!a) t->next = b;
    if(!b) t->next = a;
    
    a = b = t = nullptr;
    delete a;
    delete b;
    delete t;
    
    return dum->next;
}
// returns true list having any loop
bool isloop(Node* head) { 

    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next) {
        if(slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

// Main function
int main () {
    Node* root = nullptr;

    append (&root, 1);
    append (&root, 2);
    append (&root, 3);
    append (&root, 4);
    append (&root, 5);

    print(root);

    // cout << boolalpha << isloop (root) << '\n';

    cout <<"EXIT_SUCCESS...";
}