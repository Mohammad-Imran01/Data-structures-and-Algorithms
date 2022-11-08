#include <iostream>
using namespace std;

// Class for Symmetric matrix.. Indices starts from 1
class Symmetry {
private:
    int *a;
    int dimen;
    int size;
public:
    Symmetry (int dim=3) {
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
void Symmetry::set (int i, int j, int val) {
    if (i < j) swap(i, j);
    a[(i*(i-1)/2) + j-1] = val;
}
int Symmetry::get (int i, int j) {
    if (i < j) swap (i, j);
    return a[(i*(i-1)/2)+j-1];
}
void Symmetry::print() {
    for (int i = 1; i < dimen; i++) {
        for (int j = 1; j < dimen; j++) {
            if (i < j) cout << get(j, i) << " ";
            else cout << get(i, j) << " ";
        }
        cout << endl;
    }
}


// Class for Tri-Diagonal Matrix.. Indices starts from 1
class TriDiagonal {
private:
    int dimen;
    int* a;
    int size;
public:
    TriDiagonal (int n) {
        dimen = n+1;
        size = 3*n - 2;
        a = new int[size];
        for (int i = 0; i < size; i++)  a[i] = 0;
    }
    void print ();
    void set (int i, int j, int val);
    int get (int i, int j);
    void read();
};
void TriDiagonal::print (){
    for (int i = 1; i < dimen; i++) {
        for(int j = 1; j < dimen; j++) {
            cout << get (i, j) << " ";
        }
        cout << endl;
    }
}
void TriDiagonal::set (int i, int j, int val){
    if (i - j == -1) {
        a[2*dimen-1 + i-1] = val;
    } else  if (i-j == 0){
        a[dimen -1 + i-1] = val;
    } else if (i - j == 1) {
        a[i-1] = val;
    }    
}
int TriDiagonal::get (int i, int j){
    if (i - j == -1) {
        return a[2*dimen-1 + i-1];
    } else  if (i-j == 0){
        return a[dimen -1 + i-1];
    } else if (i - j == 1) {
        return a[i-1];
    } 
    return 0;
}
void TriDiagonal::read () {
    for(int i = 1; i < dimen; i++) {
        for (int j = 1; j < dimen; j++) {
                set(i, j, (i*10+j));
        }
    }
}



int main () {
    TriDiagonal s(60);
    s.read();
    s.print();
    

    return 0;
}