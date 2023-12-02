#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> was;
bool cycle = false;

void bfs(int v, vector<int> &ts) {
    was[v] = 1;
    for(int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(was[u] == 1) {
            cycle = true;
            return;
        }
        if(was[u] == 0) {
            bfs(u, ts);
        }
    }
    was[v] = 2;
    ts.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> ts;
    g.resize(n + 1);
    was.resize(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for(int i = 1; i <= n; i++) {
        if (cycle) {
            cout << "Impossible";
            return 0;
        }
        if(was[i] == 0)
            bfs(i, ts);
    }

    cout << "Possible" << endl;
    for(int i = ts.size() - 1; i >= 0; i--) {
        cout << ts[i] << " ";
    }
    return 0;
}