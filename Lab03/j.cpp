#include <iostream>
#include <cmath>
using namespace std;

bool possible(int arr[], int n, int h, int mid) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += ceil(double(arr[i])/mid);
    }
    return cnt <= h;
}

int main() {
    int n, h;
    cin >> n >> h;
    int arr[n];
    int l = 0, r = 0, mid;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > r) r = arr[i];
    }

    while(l <= r) {
        mid = (l + r) / 2;
        if(possible(arr, n, h, mid)) {
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    if (l == 0) l++;
    cout << l;
    return 0;
}