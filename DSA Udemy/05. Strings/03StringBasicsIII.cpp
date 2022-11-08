//Permutations of a string
#include <iostream>
using namespace std;

void permut (char str[], int n) {
    static int a[10]{0};
    static char res[10];
    if (str[n] == '\0') {
        res[n] = '\0';
        cout << res << " ";
    } else {
        for (int i = 0 ; str[i] != '\0'; i++) {
            if(a[i] == 0) {
                res[n] = str[i];
                a[i] = 1;
                permut(str, n+1);
                a[i] = 0;
            }
        }
    }
}

int main () {
    char a[] = "abcdefghijlmnopqrstuvwxyz";
    permut (a, 0);
}