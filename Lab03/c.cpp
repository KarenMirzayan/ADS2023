#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < q; i++) {
        int l1, r1, l2, r2, cnt = 0;
        cin >> l1 >> r1 >> l2 >> r2;
        for(int j = 0; j < n; j++){
            if((arr[j] >= l1 && arr[j] <= r1)||(arr[j] >= l2 && arr[j] <= r2)){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    
}