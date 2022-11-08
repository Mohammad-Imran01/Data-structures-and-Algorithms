#include <iostream>
using namespace std;

class element {
public:
    int i, j, val;
};
class sparse {
private:
    element *ele;
    int m, n, nums;
public:
    sparse (int i, int j, int all_ele) {
        m = i+1;
        n = j+1;
        nums = all_ele; 
        ele = new element[nums];
    }
    ~sparse() { delete[] ele; }

    // read all elements from user one by one
    friend istream& operator>>(istream& is, sparse& s);
    //print all element
    friend ostream& operator<<(ostream& os, sparse& s);
    //Overloading + operator to add matrices
    sparse operator+(sparse& s);
};

sparse sparse::operator+(sparse& s) {
    int i{}, j{}, k{};
    if (s.m != m || n != s.n) return sparse(0,0,0);
    sparse* sum = new sparse(m, n, s.nums+nums) ;
        
    while (i < nums && j < s.nums) {
        if (ele[i].i < s.ele[j].i) {
            sum->ele[k++] = ele[i++];
        } else if (ele[i].i > s.ele[j].i) {
            sum->ele[k++] = s.ele[j++];
        } else {
            if (ele[i].j < s.ele[j].j) {
                sum->ele[k++] = ele[i++];
            } else if (ele[i].j > s.ele[j].j) {
                sum->ele[k++] = s.ele[j++];
            } else {
                sum->ele[k] = ele[i++];
                sum->ele[k++].val += s.ele[j++].val;
            }
        }
    }
    
    for(; i < nums; i++) sum->ele[k++] = ele[i];
    for(; j < s.nums; j++) sum->ele[k++] = s.ele[j];

    sum->nums=k;
    return *sum;
}
istream& operator>>(istream& is, sparse& s) {
    cout << "Enter " << s.nums << " elments: \n";
    cout << "row col val: \n";
    for (int i = 0; i < s.nums; i++) {
        cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].val;
    }
    return is;
}
ostream& operator<<(ostream& os, sparse& s) {
    int k{};
    for(int a = 1; a < s.m; a++) {
        for(int b = 1; b < s.n; b++) {
            if (s.ele[k].i == a && s.ele[k].j == b) {
                cout << s.ele[k++].val << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return os;
}

int main () {
    sparse a (3, 3, 2), b (3, 3, 1);
    cin >> a >> b;
    sparse c = a + b;
    cout << "First Matrix: " << endl << a;
    cout << "Second Matrix: " << endl << b;
    cout << "Third Matrix: " << endl << c;




    cout << "Exit Success....";
    return 0;
}