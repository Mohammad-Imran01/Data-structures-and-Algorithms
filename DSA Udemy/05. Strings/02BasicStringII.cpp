#include <iostream>
using namespace std;

void repititions (bool case_sensi = false, string str = "Are you going to test meA") {
    if (case_sensi) {
        // lower 97-122, upper 65-90
        int az[26] { 0 };
        int AZ[26] { 0 };

        for(char i : str) {
            if (i >= 'a' && i <= 'z') 
                az[i - 'a']++;
            else if (i >= 'A' && i <= 'Z') 
                AZ[i - 'A' ]++;
        }


        for(int i = 0; i < 26; i++) 
            if (az[i] > 1) cout << (char)(i+'a') << ' ' << az[i] << endl;  
        cout << endl;

        for(int i = 0; i < 26; i++) 
            if (AZ[i] > 1) cout << (char)(i+'A') << ' ' << AZ[i] << endl;
        cout << endl;

    } else {
        int AZ[26] { 0 };
        for(char i : str) {
            if (i >= 'a' && i <= 'z' ) 
                AZ[(int)(i-'a')]++;
            else if (i >= 'A' && i <= 'Z') 
                AZ[(int)(i-'A')]++;
        }

        for(int i = 0; i < 26; i++) 
            if (AZ[i] > 1) cout <<(char) (i+'A') << ' ' << AZ[i] << endl; 
        cout << endl;
    }
}
void repititionsII (string str) {
    int arr{}, test{}, i;
    
    for(i = 0; i < str.size(); i++) {
        test = 1;
        if (str[i] >= 'A' && str[i] <= 'Z') {
            test = test << ((int) (str[i] - 'A'));
            if (arr & test) {
                cout << str[i] << ' ';
            } else{
                arr |= test;
            }
        } else if (str[i] >= 'a' && str[i] <= 'z'){
            test = (test << (int) (str[i] - 'a'));
            if (arr & test) {
                cout << str[i] << ' ';
            } else {
                arr |= test;
            } 
        }
        
    }
}
int main () {
    return 0;
}