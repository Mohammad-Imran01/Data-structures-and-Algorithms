#include <iostream>
using namespace std;

void CaseChanger (string& str) {
    for(int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }   
}
void VowelConsonant (string& str) {
    int con{}, vow{};
    for(int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
            if (str[i] == 'a' || str[i] == 'A' ||
                str[i] == 'e' || str[i] == 'E' ||
                str[i] == 'i' || str[i] == 'I' ||
                str[i] == 'o' || str[i] == 'O' ||
                str[i] == 'u' || str[i] == 'U' )
             vow ++;
            else 
                con++;  
        }
    }   
    cout << "Consonant: " << con << " Vowel: " << vow << endl;
}
bool isValid (string str) {
    for(int i = 0; i < str.size(); i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= '0' && str[i] <= '9') ) {
             return false;
        }
    }   
    return true;
}
bool isPalin (string str) {
    for(int i = 0, j = str.size()-1; i <= j; i++, j--) {
        if(str[i] != str[j]) return false;
    }
    return true;
}
void reverse_str (string &str) {
    for(int i = 0, j = str.size()-1; i <= j; i++, j--) {
        char a;
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
    return ;
}

int main () {
    string str{"123aakskA1 "};
    cout <<  isValid (str);
}