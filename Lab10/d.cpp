#include <bits/stdc++.h>
using namespace std;

vector<int> g[(int)1e4];
int inf[(int)1e4];


void bfs(int y){
    queue <int> q;
    q.push(y);
    inf[y] = 0;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for(int i = 0; i < g[k].size(); i++){
            int l = g[k][i];
            if(inf[l] > inf[k] + 1){
                inf[l] = inf[k] + 1;
                q.push(l);
            }
        }
    }
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        int a, b; 
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        inf[i] = 1e9;
    }

    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if(x == 1) {
            bfs(y);
        }
        else{
            if(inf[y] == 1e9) 
                cout << -1 << "\n";
            else 
                cout << inf[y] << "\n";
        }
    }
    cout << endl;

}