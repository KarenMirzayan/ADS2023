#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	unsigned long long l = 0, r = 1e15, mid, cnt, sum;
	while (l < r) { 				
		mid = (l + r) / 2;
		cnt = 1;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < sum + arr[i]) {
				sum = 0;
				cnt++;
			}
			if (mid < arr[i]) {
				cnt = k + 1; 
			}
			sum += arr[i];
		}
		if (cnt > k) {
			l = mid + 1;
		} 
		else if (cnt <= k) {
			r = mid;
		}
	}
	cout << l;
	return 0;
}