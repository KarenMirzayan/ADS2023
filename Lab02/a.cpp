#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n, pos;
    int min = INT_MAX;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < n; i++){
        a[i] = abs(a[i] - k);
        if (a[i] < min){
            min = a[i];
            pos = i;
        }
    }
    cout << pos;
    return 0;
}