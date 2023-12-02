#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 0;
    int sum = 0;
    int minLen = n + 1;

    while (right < n) {
        sum += arr[right];

        while (sum >= k) {
            minLen = min(minLen, right - left + 1);
            sum -= arr[left];
            left++;
        }

        right++;
    }

    cout << minLen << endl;

    return 0;
}
