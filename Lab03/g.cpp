#include <iostream>
#include <cmath>

using namespace std;

bool cond(int arr[], int n, int f, int mid) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += ceil(double(arr[i]) / mid);
    }
    return cnt <= f;
}
int main() {
    int n, f;
    cin >> n >> f;
    int arr[n];
    int l = 0, r = 0, mid;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > r) r = arr[i];
    }
    while(l <= r) {
        mid = (l + r) / 2;
        if (cond(arr, n, f, mid)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    // if (l == 0) l++;
    cout << l;
    return 0;
}