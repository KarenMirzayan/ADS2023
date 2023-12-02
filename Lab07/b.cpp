#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> a, int n, vector<int> b, int m) {
    vector<int> out;
    int i = 0, j = 0, k = 0;
    while(i < n && j < m) {
        if (a[i] <= b[j]) {
            out.push_back(a[i]);
            k++;
            i++;
        }
        else{
            out.push_back(b[j]);
            k++;
            j++;
        }
    }
    while(i < n) {
        out.push_back(a[i]);
        i++;
    }
    while(j < m) {
        out.push_back(b[j]);
        j++;
    }
    return out;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<int> ans = merge(a, n, b, m);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}