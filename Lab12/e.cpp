#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, cost;

    Edge(int a, int b, int cost) {
        this->a = a;
        this->b = b;
        this->cost = cost;
    }
};

int n, v;
vector<Edge> e;
const int INF = 1e9;
bool noNegCycle = false;

void solve() {
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j = 0; j < n * n; ++j){
            if (d[e[j].a] < INF){
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
            }
        }
    }

    if (x == -1)
        noNegCycle = false;
    else {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];
        
        vector<int> path;
        for (int cur = y; ; cur = p[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }

        reverse(path.begin(), path.end());

        cout << "YES" << endl << path.size() << endl;
        for (int i=0; i<path.size(); ++i)
            cout << path[i] + 1 << ' ';

        noNegCycle = true;
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int cost;
            cin >> cost;
            e.push_back(Edge(i, j, cost));
        }
    }
    for (int i = 0; i < n; i++){
        v = i;
        solve();
        if (noNegCycle) break;
    }
    if (!noNegCycle)
        cout << "NO" << endl;
}