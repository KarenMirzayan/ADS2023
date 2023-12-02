#include <bits/stdc++.h>
using namespace std;

vector<int> was;
vector<vector<int>> adj_list;

bool dfs(int u) {
    was[u] = 1;
    for (int i = 0; i < adj_list[u].size(); i++) {
        int v = adj_list[u][i];
        if (v == 0) continue;
        if (was[v] == 1) {
            return true;
        }
        if (was[v] == 0) {
            if (dfs(v)) {
                return true;
            }
        }
    }
    was[u] = 2;
    return false;
}

int main() {
    int n, m, cnt = 0;
    bool cycle = false;
    cin >> n >> m;
    adj_list.resize(n + 1);
    was.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < adj_list[i].size(); j++) {
            int neighbor = adj_list[i][j];
            adj_list[i][j] = 0;
            for (int l = 1; l <= n; l++) {
                if (was[l] == 0) {
                    bool f = dfs(l);
                    if (f) {
                        cycle = true;
                        break;
                    }
                }
            }
            if (!cycle) {
                cout << "YES";
                return 0;
            }
            adj_list[i][j] = neighbor;
            was.assign(n + 1, 0);
            cycle = false;
        }
    }
    cout << "NO";

    return 0;
}
