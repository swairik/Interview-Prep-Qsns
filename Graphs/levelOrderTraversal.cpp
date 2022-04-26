#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges;
vector<bool> vis;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto x : edges[node]) {
            if(vis[x])  continue;
            q.push(x);
            vis[x] = true;
        }
    }
}

int main() {
    // n vertices, m edges
    int n, m;
    cout << "enter the number of vertices : ";
    cin >> n;
    cout << "enter the number of edges : ";
    cin >> m;

    edges = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    bfs(0);
    

}