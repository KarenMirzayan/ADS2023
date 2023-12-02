#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


pair<int, int> binarySearchNestedList(const vector<vector<int>>& nestedList, int target) {
    int rows = nestedList.size();
    int cols = nestedList[0].size();

    int left = 0, right = rows * cols - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int row = mid / cols;
        int col = mid % cols;

        if (nestedList[row][col] == target) {
            return make_pair(row, col);
        } else if (nestedList[row][col] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return make_pair(-1, -1);
}

int main() {
    int t;
    cin >> t;
    int arr[t];
    for(int i = 0; i < t; i++) {
        cin >> arr[i];
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> brr(n, vector<int>(m, 0));
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < m; j++) {
            cin >> brr[i][j];
        }
        sort(brr[i].begin(), brr[i].end());
    }

    for(int i = 0; i < t; i++) {
        pair<int, int> p = binarySearchNestedList(brr, arr[i]);
        if(p.first == -1) {
            cout << "-1 \n";
            continue;
        }
        p.first = (n - p.first - 1);
        if(p.first % 2 == 0) {
            p.second = m - p.second - 1;
        }
        cout << p.first << " " << p.second << endl;
    }
}