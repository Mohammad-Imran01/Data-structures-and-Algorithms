#include <iostream>
#define size 10
using namespace std;

void insert(int h[], int val) {
    int i { val%10 };
    if(h[i] == 0) h[i] = val;
    else i++;
    while(h[i++] != 0 && i != val%10) 
        if(i == size) i = 0;
        else i++;
    if(i == val%10) return;
    else if (h[i] == 0) h[i] = val;
}

int search (int h[], int val) {
    if(h[val%10] == val) return 1;
    if(h[val%10] == 0) return 0;
    else { int i = (val%10)+1;
        while(h[i++] != 0 && i != val%10 && h[i] != val) 
            if(i == size) i = 0;
            else i++;
        if(i == val%10 || h[i] == 0) return 0;
        else return 1;
    }
    return 0;
}

int main () {
    int hash[size]{};
    insert(hash, 1);
    insert(hash, 10);
    insert(hash, 3);
    insert(hash, 7);
    insert(hash, 20);
    insert(hash, 30);
    insert(hash, 11);

    cout << search(hash, 11);

}