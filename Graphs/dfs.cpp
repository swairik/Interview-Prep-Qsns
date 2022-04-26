#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges;
vector<bool> vis;

void dfs(int node, int par) {
    vis[node] = true;
    
    cout << node << " ";

    for(auto x : edges[node]) {
        if(x == par || vis[x])  continue;
        dfs(x, node);
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

    dfs(0, -1);
}