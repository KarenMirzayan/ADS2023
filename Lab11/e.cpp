#include <bits/stdc++.h>
using namespace std;

vector <int> parent;

int get(int v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = get(parent[v]);
}

bool unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a != b){
        parent[a] = b;
        return true;
    }
    return false;
}

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;

    vector<vector<int>> v(n);
    parent.resize(n);

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector <int> numOfComps;
    for(int i = n - 1; i >= 0; i--){
        numOfComps.push_back(cnt++);
        for(int neighbour: v[i]){
            if(neighbour > i){
                if(unite(i, neighbour))
                    cnt--;
            }
        }
    }
    for(int i = numOfComps.size() - 1; i >= 0; i--){
        cout << numOfComps[i] << endl;
    }

}