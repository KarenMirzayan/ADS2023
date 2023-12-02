#include <iostream>
#include <vector>

using namespace std;

const int INF = 101;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> edges[i][j];
        }
    }

    vector<bool> visited(n);
    vector<int> minCost(n, INF);

    minCost[0] = 0;
    int totalCost = 0;

    for(int i = 0; i < n; i++) {
        int v = -1;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && (v == -1 || minCost[j] < minCost[v])) {
                v = j;
            }
        }
        visited[v] = true;
        totalCost += minCost[v];
        for(int j = 0; j < n; j++) {
            if (edges[v][j] < minCost[j]) {
                minCost[j] = edges[v][j];
            }
        }
    }
    cout << totalCost;
    return 0;
}