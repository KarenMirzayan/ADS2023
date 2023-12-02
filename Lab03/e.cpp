#include <iostream>
#include <vector>
using namespace std;

struct rect {
    int x1, y1, x2, y2;
};

bool check(vector<rect> v, int mid, int k) {
    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        if(max(v[i].x2, v[i].y2) <= mid) {
            cnt++;
        }
    }
    return cnt >= k;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<rect> v;
    int l = 0, r = 0, mid;
    for(int i = 0; i < n; i++) {
        rect tmp;
        cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
        v.push_back(tmp);
        r = max(max(tmp.x2, tmp.y2), r);
    }

    while(l <= r) {
        mid = (l + r) / 2;
        // cout << mid << " ";
        if (check(v, mid, k)) {
            r = mid - 1;
        }
        else 
            l = mid + 1;
        
    }
    cout << l;
}