#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<int> islands(n);
    for (int i = 0; i < n; i++) {
        cin >> islands[i];
    }

    vector<bool> visited(n, false);
    vector<int> minCost(n, INF);

    minCost[0] = 0;
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (v == -1 || minCost[j] < minCost[v]))
                v = j;
        }
        if (minCost[v] == INF) {
            cout << "Graph is not connected!" << endl;
            return 0;
        }

        visited[v] = true;
        totalCost += minCost[v];

        for (int u = 0; u < n; u++) {
            int cost = islands[v] + islands[u];
            if (cost < minCost[u])
                minCost[u] = cost;
        }
    }

    cout << totalCost << endl;
    return 0;
}
