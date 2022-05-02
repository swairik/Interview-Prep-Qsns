#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

/* graph to use
9 14
0 1 4
0 7 8
1 7 11
2 1 8
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/

vector<vector<pair<int, int>>> edges;
vector<vector<int>> mat;

vector<int> restore_path(int src, int v, vector<int> &parent) {
    vector<int> ans;

    for(int i = v; i != src; i = parent[i]) {
        ans.push_back(i);
    }
    ans.push_back(src);
    reverse(ans.begin(), ans.end());

    return ans;
}

void dijkstraUsingAdjacencyMatrix(int src, int n) {
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    vector<bool> vis(n, false);

    dist[src] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        if(u == -1 || dist[u] == INF) {
            break;
        }

        vis[u] = true;
        for(int v = 0; v < n; v++) {
            int d = mat[u][v];
            if(!d)  continue;
            if(dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                parent[v] = u;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << "Dist to  " << i << " : " << dist[i] << "-----PATH : ";
        vector<int> path = restore_path(src, i, parent);
        for(auto x : path) {
            cout << x << " ";
        }
        cout << endl;
    }

}

void dijkstraUsingAdjacencyList(int src, int n) {
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    vector<bool> vis(n, false);

    dist[src] = 0;

    for(int i = 0; i < n; i++) {
        int u = -1;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if(u == -1 || dist[u] == INF) {
            break;
        }

        vis[u] = true;
        for(auto x : edges[u]) {
            int v = x.first;
            int d = x.second;

            if(dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                parent[v] = u;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << "Dist to " << i << " : " << dist[i] << "----PATH : ";
        vector<int> path = restore_path(src, i, parent);
        for(auto x : path) {
            cout << x << " ";
        }
        cout << endl;
    }

}

int main() {
    int n, m;
    cout << "enter the number of vertices & the number of edges : ";
    cin >> n >> m;

    edges = vector<vector<pair<int, int>>> (n);
    mat.assign(n, vector<int> (n, 0));

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // create adjacency list
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
        // create adjacency matrix
        mat[u][v] = w;
        mat[v][u] = w;
    }

    cout << "Using adjacency List : " << endl;
    dijkstraUsingAdjacencyList(0, n);
    cout << "Using adjacency Matrix : " << endl;
    dijkstraUsingAdjacencyMatrix(0, n);

}