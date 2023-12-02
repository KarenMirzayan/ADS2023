#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INF = (int)1e9;

int n;
vector<vector<pair<int, int>>> g;

int dijkstra(int x, int y) {
    if (x == y)
        return 0;
    vector<int> d(n, INF);
    d[x] = 0;
    set< pair<int, int> > q;
    q.insert({d[x], x});
    while (!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        
        for(int i = 0; i < g[v].size(); i++) {
            int u = g[v][i].first;
            int len = g[v][i].second;
            if(d[v] + len < d[u]) {
                q.erase({d[u], u});
                d[u] = d[v] + len;
                q.insert({d[u], u});
            }
        }
    }
    return d[y];
}

int main () {
    int m;
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    int s, a, b, f;
    cin >> s >> a >> b >> f;
    s--;
    f--;
    a--;
    b--;
    int ans1 = dijkstra(s, a) + dijkstra(a, b) + dijkstra(b, f);
    int ans2 = dijkstra(s, b) + dijkstra(b, a) + dijkstra(a, f);
    if (min(ans1, ans2) < INF)
        cout << min(ans1, ans2);
    else
        cout << -1;
    return 0;
}