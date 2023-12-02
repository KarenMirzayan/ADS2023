#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, remaining_shrooms = 0, minutes = 0;
    cin >> n >> m;
    int a[n + 2][m + 2];
    queue<pair<int, int>> q;
    for(int i = 0; i < n + 2; i++) {
        for(int j = 0; j < m + 2; j++) {
            if(i == 0 || j == 0 || i == n + 1 || j == m + 1) {
                a[i][j] = 3;
                continue;
            }
            cin >> a[i][j];
            if(a[i][j] == 2) {
                q.push({i, j});
            }
            else if(a[i][j] == 1) {
                remaining_shrooms++;
            }
        }
    }
    while(!q.empty()) {
        if(!remaining_shrooms)
            break;
        int size = q.size();
        while(size--) {
            pair<int, int> position = q.front();
			q.pop();
			int i = position.first;
			int j = position.second;
            if(a[i - 1][j] == 1) {
                a[i - 1][j] = 2;
                q.push({i - 1, j});
                remaining_shrooms--;
            } 
            if(a[i + 1][j] == 1) {
                a[i + 1][j] = 2;
                q.push({i + 1, j});
                remaining_shrooms--;
            }
            if(a[i][j - 1] == 1) {
                a[i][j - 1] = 2;
                q.push({i, j - 1});
                remaining_shrooms--;
            } 
            if(a[i][j + 1] == 1) {
                a[i][j + 1] = 2;
                q.push({i, j + 1});
                remaining_shrooms--;
            }
        }
        minutes++;
    }
    if(!remaining_shrooms) 
        cout << minutes;
	else 
        cout << -1;
}