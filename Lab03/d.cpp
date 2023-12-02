#include <iostream>
#include <algorithm>

using namespace std;

int binary_left(int arr[], int n, int k) {
    int leftIndex = -1;
    int l = 0;
    int r = n - 1;
    int mid;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(arr[mid] == k) {
            leftIndex = mid;
            r = mid - 1;
        }
        else if (k < arr[mid]){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    if (leftIndex == -1)
        return l;
    return leftIndex;
}

int binary_right(int arr[], int n, int k) {
    int rightIndex = n + 1;
    int l = 0;
    int r = n - 1;
    int mid;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(arr[mid] == k) {
            rightIndex = mid;
            l = mid + 1;
        }
        else if (k < arr[mid]){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    if (rightIndex == n+1)
        return r;
    return rightIndex;
}
int main() {
    int n, q;
    cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int l1, r1, l2, r2;
    int cnt;
    for(int i = 0; i < q; i++) {
        cnt = 0;
        cin >> l1 >> r1 >> l2 >> r2;
        l1 = binary_left(arr, n, l1);
        r1 = binary_right(arr, n, r1);
        l2 = binary_left(arr, n, l2);
        r2 = binary_right(arr, n, r2);
        for(int j = min(l1, l2); j <= max(r1, r2); j++) {
            if( (j >= l1 && j <= r1)||(j >= l2 && j <= r2) ){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}