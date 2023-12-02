#include <bits/stdc++.h>

using namespace std;

int n, m, cnt = 0;
vector <bool> saw;
vector <vector <int> > v;

void bigFam(int par) {
    saw[par] = true;
    for(int i = 0; i < v[par].size(); i++) {
        if(!saw[v[par][i]]) {
            if(v[v[par][i]].size() > v[par].size()) {
                cnt++;
            }
            bigFam(v[par][i]);
        }
    }
}

int main() {
    cin >> n >> m;
    saw.resize(n);
    v.resize(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        v[x].push_back(y);
    }
    for(int i = 0; i < n; i++) {
        if (!saw[i]) {
            bigFam(i);
        }
    }
    cout << cnt + abs(n-m);
}