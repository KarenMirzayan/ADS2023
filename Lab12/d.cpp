#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
int n;
vector< pair<long long, long long> > g;
vector<long long> d;
vector<bool> was;

long long dijkstra(long long s, long long f){
    vector<long long> d(n + 1, INF);
    vector<bool> was(n + 1, false);

    d[s] = 0;

    for(int i = 0; i < n; i++){
        long long v = -1;

        for(int j = 0; j < n; j++){
            if (!was[j] && (v == -1 || d[j] < d[v])){
                v = j;
            }
        }

        was[v] = true;

        for(int j = 0; j < n; j++){
            long long to = j;
            long long len = abs(g[j].first - g[v].first) + abs(g[j].second - g[v].second);
            d[to] = min(d[to], max(d[v], len));
        }
    }
    return d[f];
}

int main(){
    cin >> n;
    g.resize(n + 1);
    for(int i = 0; i < n; i++){
        cin >> g[i].first >> g[i].second;
    }
    cout << dijkstra(0, n-1);
    return 0;
}