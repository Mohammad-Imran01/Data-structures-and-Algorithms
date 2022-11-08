#include <iostream>
#include <algorithm>
using namespace std;
#include <stack>

//false means out;
int pre(char c, bool in = false ) {
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return 10;
    if(in) {        
        if(c == '*' || c == '/') 
            return 4;
        if (c == '+' || c == '-') 
            return 2;
        if (c == '^') 
            return 5;
        if (c == '(') 
            return 0;
    } else {
        if(c == '*' || c == '/') 
            return 3;
        if (c == '+' || c == '-') 
            return 1;
        if (c == '^') 
            return 6;
        if (c == '(') 
            return 7;
    }
}

string postfix (string str) {
    stack <char> s;
    string ans;
    for(int i = 0; i < str.size(); i++) {                   
        if(s.empty() || (pre(s.top()) < pre(str[i])))   
            s.push(str[i]);
        else {
            while(!s.empty() && (pre(s.top()) >= pre(str[i]))) {
                if(s.top() != '(' && s.top() != ')')
                ans.push_back(s.top()); 
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(! s.empty() ) {
        if(s.top() == '(' || s.top() == ')') 
            s.pop();
        else 
            ans += s.top(), s.pop();
    }      
    return ans;
}

int evalute (string exp) {
    exp = postfix(exp);
    cout << exp << endl;
    stack <int> s;

    for(int i = 0; i < exp.size(); i++) {
        if(exp[i] >= '0' && exp[i] <= '9') {
            s.push((int)(exp[i]-'0'));
        } else if (exp[i] == '-' ||exp[i] == '+' ||exp[i] == '/' ||exp[i] == '*' ){
            int x1, x2;
            x2 = s.top(), s.pop(); x1 = s.top(), s.pop();

            if(exp[i] == '+') {
                s.push((x1 + x2));
            } else if (exp[i] == '-') {
                s.push((x1 - x2));
            } else if(exp[i] == '*') {
                s.push((x1 / x2));
            } else if (exp[i] == '/') {
                s.push((x1 * x2));
            }           
        }   
    }
    return s.top();
}

int main (){
    cout << evalute("1*2");
    cout <<""
;}