#include <bits/stdc++.h>

using namespace std;

int main() {
    // Creates a min heap
    priority_queue <long long, vector<long long>, greater<long long> > pq;
    
    long long n, m, a;
    cin >> n >> m;
    for(long long i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }
    long long cnt = 0;
	long long x, y;
    while(pq.top() < m) {
		if(pq.size() <= 1) {
			cout << -1;
			return 0;
		}
		// print();
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        pq.push(x + 2 * y);
		cnt++;
    }
    cout << cnt;
}