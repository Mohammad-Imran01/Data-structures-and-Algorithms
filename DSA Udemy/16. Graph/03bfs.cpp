#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// takes two-dim vector return dfs of the graph in a vector
vector <int> bfs (vector <vector <int>> g, int beg=1) {
    queue <int> q;
    vector <bool> vis(g.size(),0);
    vector <int> bfs;

    vis[beg] = true;
    q.push(beg);
    bfs.push_back(beg);

    while(!q.empty()) {
        int i = q.front();
        q.pop();

        for(int j = 0; j < g.size(); j++) {
            if(g[i][j] && !vis[j]) {
                vis[j] = true;
                bfs.push_back(j);
                q.push(j);
            }
        }

    }
    return bfs;
}
void print(vector <int> v) {
    cout << "\nBFS: ";
    for(int x: v) 
        cout << x << ' ';
    cout << endl;
}

int main () {
    vector <vector<int>> v = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0}
    };
    for(int i = 1; i < 6; i++)
    print(bfs(v, i));
}