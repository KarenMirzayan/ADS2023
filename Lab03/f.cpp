#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int p;
    cin >> p;
    int k;
    for(int i = 0; i < p; i++) {
        int sum = 0, cnt = 0;
        cin >> k;
        for(int j = 0; j < n; j++) {
            if(arr[j] <= k){
                cnt++;
                sum += arr[j];
            }
        }
        cout << cnt << " " << sum << endl;
    }
    return 0;
}