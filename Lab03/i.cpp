#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int x;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    int l = 0, r = n-1, mid;
    while(l <= r) {
        mid = (l + r)/2;
        if(x <= arr[mid]) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    arr[l] == x ? cout << "Yes" : cout << "No";
}