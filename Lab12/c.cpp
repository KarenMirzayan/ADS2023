#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

const int INF = (int)1e9;

int n;
int arr[405][405];

void bfs(vector<int> &d, vector<bool> &saw, vector<vector<int>> g) {
    queue<int> q;
    q.push(0);
    saw[0] = true;
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for(int i = 0; i < g[k].size(); i++) {
            int dest = g[k][i];
            if(!saw[dest]) {
                saw[dest] = true;
                q.push(dest);
                d[dest] = d[k] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > g1(n), g2(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g1[x].push_back(y);
        g1[y].push_back(x);
        arr[x][y] = arr[y][x] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 0 && i != j) {
                g2[i].push_back(j);
            }
        }
    }

    vector<int> d1(n, 0);
    vector<bool> saw1(n, false);
    vector<int> d2(n, 0); 
    vector<bool> saw2(n, false);

    bfs(d1, saw1, g1);
    bfs(d2, saw2, g2);

    if(!saw1[n-1] || !saw2[n-1]) {
        cout << -1;
    }
    else {
        cout << max(d1[n-1], d2[n-1]);
    }
    return 0;
}