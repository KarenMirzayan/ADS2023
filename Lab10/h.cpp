#include <bits/stdc++.h>

using namespace std;
int n, m, cnt = 0;

void dfs(char **a, int i, int j){
	if(i < 0 || j < 0 || i >= n || j >= m || a[i][j] == '0') return;
	a[i][j] = '0';
	dfs(a, i + 1, j);
	dfs(a, i - 1, j);
	dfs(a, i, j + 1);
	dfs(a, i, j - 1);
}

int main() {
    cin >> n >> m;
    char **a = new char* [n];
    for(int i = 0; i < n; i++) {
        a[i] = new char[m];
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '1') {
                dfs(a, i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}