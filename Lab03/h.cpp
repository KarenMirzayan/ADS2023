#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int arr[n], brr[n], sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        brr[i] = sum;
    }
    int l = 0, r = n - 1, k, mid;
    for(int i = 0; i < m; i++) {
        cin >> k;
        l = 0, r = n - 1;
        while (l <= r) {
            mid = (l + r)/2;
            if (k <= brr[mid]) {
                r = mid - 1;
            }
            else if (k > brr[mid]) {
                l = mid + 1;
            }
        }
        cout << l + 1 << endl;
    }
}