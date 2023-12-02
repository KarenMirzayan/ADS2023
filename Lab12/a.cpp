#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

int main() {
    int n;
    cin >> n;
    int arr[n+1][n+1];
    int g[n+1][n+1];
    int p[n+1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            g[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        int res = 0;
        for(int j = 1; j <= i; j++) {
            int a = p[j], b = p[i];
            g[a][b] = arr[a][b];
            g[b][a] = arr[b][a];
        }

        for(int k = 1; k <= i; k++) {
            for(int t = 1; t <= i; t++) {
                int a = p[t], b = p[i], c = p[k];
                if (g[a][c] + g[c][b] < g[a][b])
                    g[a][b] = g[a][c] + g[c][b];
            }
        }
        for(int k = 1; k <= i; k++) {
            for(int t = 1; t <= i; t++) {
                int a = p[i], b = p[t], c = p[k];
                if (g[a][c] + g[c][b] < g[a][b])
                    g[a][b] = g[a][c] + g[c][b];
            }
        }
        
        for(int k = 1; k <= i; k++) {
            for(int t = 1; t <= i; t++) {
                int a = p[k], b = p[t], c = p[i];
                if (g[a][c] + g[c][b] < g[a][b])
                    g[a][b] = g[a][c] + g[c][b];
                if(g[a][b] < INF) 
                    res = max(res, g[a][b]);
            }
        }
        cout << res << endl;
    }
}
