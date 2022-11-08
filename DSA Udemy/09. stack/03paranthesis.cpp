#include <iostream>
#include <stack>
using namespace std;

bool match (string str) {
    stack <char> s;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') 
            s.push(str[i]);
        
        if(str[i] == ']') {
            if(s.empty()) return false;
            if (s.top() == '[')     
                s.pop();
            else 
                return false;
        }

        if(str[i] == '}') {
            if(s.empty()) return false;
            if (s.top() == '{')     
                s.pop();
            else 
                return false;
        }
        if(str[i] == ')') {
            if(s.empty()) return false;
            if (s.top() == '(')     
                s.pop();
            else 
                return false;
        }
    
    }
    return s.empty();
}


int main () {
    clearerr;

    // cout << boolalpha << boolalpha << boolalpha << match("{([])}");
    cout << (char)92;
    return 0;
}