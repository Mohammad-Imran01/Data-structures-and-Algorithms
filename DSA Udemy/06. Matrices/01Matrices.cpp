#include <iostream>
using namespace std;

//Class for diagonal matrix, indices starts from 0
class diagonal {
private:
    int size;
    int *a;
public:
    diagonal (int dim=3) {
        if (dim < 0) return;
        this->size = dim;
        a = new int[size];
        for(int i = 0; i < size; i++) a[i] = 0;        
    }
    void set(int m, int n, int val);
    int get(int m, int n);
    void print();
};
void diagonal::set(int m, int n, int val) {
    if (m != n || m > size || n < 0) return;
    a[m] = val;
}
int diagonal::get (int m, int n) {
    if (m != n || m > size || n < 0) return 0;
    return a[m];
}
void diagonal::print() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) cout << a[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}



// Class for lower traingular matrix using row major indices starts from 1
class lowerRow {
private:
    int *a;
    int dimen;
    int size;
public:
    lowerRow (int dim=3) {
        if (dim <= 0) return;
        dimen = dim+1;
        size = (dimen*(dimen-1))/2;
        a = new int[size];
        for(int i = 0; i < size; i++) a[i] = 0;        
    }
    void set(int i, int j, int val);
    int get(int i, int j);
    void print();
};
void lowerRow::set (int i, int j, int val) {
    if (i < j) return;
    a[(i*(i-1)/2) + j-1] = val;
}
int lowerRow::get (int i, int j) {
    if (i < j) return 0;
    return a[(i*(i-1)/2)+j-1];
}
void lowerRow::print() {
    for (int i = 1; i < dimen; i++) {
        for (int j = 1; j < dimen; j++) {
            if (i < j) cout << "0 ";
            else cout << get(i, j) << " ";
        }
        cout << endl;
    }
}
// Class for lower traingular matrix using col major indices starts from 1
class lowerCol {
private:
    int *a;
    int dimen;
    int size;
public:
    lowerCol (int dim=3) {
        if (dim <= 0) return;
        dimen = dim+1;
        size = (dimen*(dimen-1))/2;
        a = new int[size];
        for(int i = 0; i < size; i++) a[i] = 0;        
    }
    void set(int i, int j, int val);
    int get(int i, int j);
    void print();
};
void lowerCol::set (int i, int j, int val) {
    if (i < j) return;
    a[(dimen*(j-1)- ((j-1)*(j-2))/2 ) + i-j] = val;
}
int  lowerCol::get (int i, int j) {
    if (i < j) return 0;
    return a[(dimen*(j-1) - ((j-1)*(j-2))/2 ) + i-j];
}
void lowerCol::print() {
    for (int i = 1; i < dimen; i++) {
        for (int j = 1; j < dimen; j++) {
            if (i < j) cout << "0 ";
            else cout << get(i, j) << " ";
        }
        cout << endl;
    }
}



// Class for upper traingular matrix using row major indices starts from 1
class UpperRow {
private:
    int *a;
    int dimen;
    int size;
public:
    UpperRow (int dim=3) {
        if (dim <= 0) return;
        dimen = dim+1;
        size = (dimen*(dimen-1))/2;
        a = new int[size];
        for(int i = 0; i < size; i++) a[i] = 0;        
    }
    void set(int i, int j, int val);
    int get(int i, int j);
    void print();
};
void UpperRow::set (int i, int j, int val) {
    if (j < i) return;
    a[(dimen*(i-1)- ((i-1)*(i-2))/2 ) + j-i] = val;
}
int  UpperRow::get (int i, int j) {
    if (j < i) return 0;
    return a[ (dimen*(i-1)- ((i-1)*(i-2))/2 ) + j-i];
}
void UpperRow::print() {
    for (int i = 1; i < dimen; i++) {
        for (int j = 1; j < dimen; j++) {
            if (j < i) cout << "0 ";
            else cout << get(i, j) << " ";
        }
        cout << endl;
    }
}
// Class for lower traingular matrix using row major indices starts from 1
class UpperCol {
private:
    int *a;
    int dimen;
    int size;
public:
    UpperCol (int dim=3) {
        if (dim <= 0) return;
        dimen = dim+1;
        size = (dimen*(dimen-1))/2;
        a = new int[size];
        for(int i = 0; i < size; i++) a[i] = 0;        
    }
    void set(int i, int j, int val);
    int get(int i, int j);
    void print();
};
void UpperCol::set (int i, int j, int val) {
    if (j < i) return;
    a[(j*(j-1)/2) + i-1] = val;
}
int UpperCol::get (int i, int j) {
    if (j < i) return 0;
    return a[(j*(j-1)/2)+i-1];
}
void UpperCol::print() {
    for (int i = 1; i < dimen; i++) {
        for (int j = 1; j < dimen; j++) {
            if (j < i) cout << "0 ";
            else cout << get(i, j) << " ";
        }
        cout << endl;
    }
}
   

int main () {
    UpperCol d(2);
    d.set(1, 1, 11);
    d.set(1, 2, 12);
    d.set(2, 2, 22);

    d.print();

    //cout << d.get(1,2);

    return 0;
}