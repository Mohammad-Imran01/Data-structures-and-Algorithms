#include <iostream>
using namespace std;

/*Call func for given val recursively then add val at returnning time*/
int getSum(int num) {
    if (num > 0) 
        return getSum (num - 1) + num;
    return 0; 
}

/*Call func for given val recursively then add a static val at returning time*/
int staticSum (int num) {
    static int x = 0;
    if (num > 0) {
        x++;
        return staticSum (num - 1) + x;
    }
    return 0; 
}

int main () {
    cout << getSum (5) << '\n' <<  staticSum (5);

    cout << "\nExit Success...\n" << endl;
}