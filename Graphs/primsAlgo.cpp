#include <bits/stdc++.h>

using namespace std;

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

void prims(int n) {
    // using set as min priority queue (min heap)
    set<pair<int, pair<int, int>>> st;
    vector<bool> vis(n, false);
    vector<vector<int>> ans;

    int total = 0;
    
    for(auto x : edges[0]) {
        st.insert({x.second, {0, x.first}});
    }

    // loop runs for n - 1 times as we have already taken in vertex 0
    for(int i = 0; i < n - 1; i++) {
        while(!st.empty()) {
            auto edge = *st.begin();
            int from = edge.second.first;
            int to = edge.second.second;

            if(!vis[to]) {
                break;
            }
            st.erase(st.begin());
        }

        if(st.empty()) {
            cout << "Total : " << total << endl;
            cout << "NO MST!!!!";
            return;
        }
        
        auto edge = *st.begin();
        st.erase(st.begin());
        int from = edge.second.first;
        int to = edge.second.second;
        int w = edge.first;
        
        
        // push all of to edges
        for(auto x : edges[to]) {
            st.insert({x.second, {to, x.first}});
        }
        
        vis[from] = true;
        vis[to] = true;

        total += w;
        ans.push_back({to, from, w});

    }

    cout << "min weight : " << total << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    edges = vector<vector<pair<int, int>>>(n);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    prims(n);

}