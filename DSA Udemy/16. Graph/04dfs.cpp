#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void set(vector <vector<int> > &v) {
    int from, to;
    cout << "Enter from to: \n";
    cin >> from >> to;
    v[from][to] = 1;
    while((cin >> from >> to)){
        v[from][to] = 1;
    }
}
void print(vector <int> v) {
    cout << "elements: ";
    for(int i : v) cout << i << ' ';
    cout << endl;
}
void print(vector <vector <int>> v) {
    cout << "elements: \n";
    
    for (vector <int> i: v) {
        for(int x: i) cout << x << ' ';
        cout << endl;
    }
    cout << endl;
}
vector <int> dfs(vector <vector<int>> g, int k=1) {
    vector <int> vis(g.size(), 0);    
    vector <int> a; stack <int> s;
    a.push_back(k); s.push(k);
    vis[k] = 1;   
    
    while(!s.empty()) {
        int i = s.top(); s.pop();
        for(int j = 1; j < 5; j++) {
            if(g[i][j] && vis[j] == 0) {
                a.push_back(j);
                s.push(j);
                vis[j] = 1;
                break;
            }
        }
    }
    return a;
}

int main () {
    vector <vector<int>> v(5, vector<int>(5,0));
    set(v);
    print(v);
    print(dfs(v,1));
    // int a;
    // cout << a;

    return 0;
}