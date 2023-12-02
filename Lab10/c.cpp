#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    vector<int> saw(1e5, 0);
    vector<int> found_b_after_operation(1e5, -100);
    int a, b;
    cin >> a >> b;
    queue<int> q;
    q.push(a);
    saw[a] = 0;
    while(!q.empty()) {
        int k = q.front();
        q.pop();
        if(k * 2 <= 1e4 && !saw[k*2]) {
            found_b_after_operation[k*2] = k;
            q.push(k*2);
            saw[k*2] = saw[k] + 1;
        }
        if(k - 1 > 0 && !saw[k-1]) {
            found_b_after_operation[k-1] = k;
            q.push(k-1);
            saw[k-1] = saw[k] + 1;
        }
    }
    cout << saw[b] << endl;
    vector<int> res;
    while(found_b_after_operation[b] != -100) {
        res.push_back(b);
        b = found_b_after_operation[b];
    }

    for(int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << " ";
    }
    return 0;
}