#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    char k;
    cin >> k;
    if (k >= a[n-1]) {
        cout << a[0];
        return 0;
    }
    int l = 0, r = n-1, mid = 0;
    while(l <= r) {
        mid = (l + r)/2;
        if(k < a[mid]) {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << a[l];
}