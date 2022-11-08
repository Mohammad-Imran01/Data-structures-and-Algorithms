// representation of a graph using adjacency matrix
#include <iostream>
#define size 5
using namespace std;

void insert (int mat[][size], int from_m, int to_n, int weight=1) {
    if(from_m-1 > size || to_n-1 > size || from_m-1 < 0 || to_n-1 < 0) return;
    mat[from_m-1][to_n-1] = weight;
    // mat[to_n-1][from_m-1] = weight;
    return;
}
void print(int mat[][size]) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}

int main () {
    int m[5][5]{};
    insert(m, 1, 1, 3);
    insert(m, 1, 3, 2);
    insert(m, 3, 1, 6);
    print(m);

}