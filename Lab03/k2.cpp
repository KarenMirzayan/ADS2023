#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    int brr[n + 1], sum = 0;
    brr[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        brr[i + 1] = sum;
    }
    int min = n - 1;
    for (int l = 0; l < n; l++) {
        int left = l;
        int f = k + brr[l];
        int r = n - 1;
        int mid;
        while(left <= r) {
            mid = (left + r) / 2;
            if (brr[mid] <= f) {
                left = mid + 1;
            }
            else if (brr[mid] > f){
                r = mid - 1;
            }
        }
        if (left < min) {
            min = left;
        }
    }
    cout << min;
}