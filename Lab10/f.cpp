#include <bits/stdc++.h>

using namespace std;

int n, m, s, f, x, y;
vector <bool> saw;
vector <vector<int> > v; 

bool dfs(int s) {
    if(f == s)
        return true;
    saw[s] == true;
    for(int i = 0; i < v[s].size(); i++) {
        int p = v[s][i];
        if(!saw[p]) {
            return dfs(p);
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    saw.resize(n);
    v.resize(n);
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int f, s;
    cin >> f >> s;
    f--;
    s--;
    dfs(s) ? cout << "YES" : cout << "NO";
}