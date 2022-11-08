#include <iostream>
#include <algorithm>
using namespace std;
#include <stack>

int pre(char c) {
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return 3;
    if(c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
}

string postfix (string str) {
    stack <char> s;
    string ans;
    for(int i = 0; i < str.size(); i++) {
        if(s.empty() || (pre(s.top()) < pre(str[i])))   
            s.push(str[i]);
        else {
            while(!s.empty() && (pre(s.top()) >= pre(str[i])))
                ans.push_back(s.top()), s.pop();
            s.push(str[i]);
        }
        

    }
    while(!s.empty()) ans += s.top(), s.pop();
    return ans;
}
int main (){
    cout << postfix({"a+b*c-d/e"});
}