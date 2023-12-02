#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

const int N = (int)1e5 + 7;
const int p = 31;

int my_hash(string s) {
	int h = 0;
	for (int i = 0; i < s.length(); i++) {
		h = h * p + s[i];
	}
	return h;
}


int main() {
	int n, m, k, cnt = 0;
	string s1, s2, w;    
	cin >> s1 >> s2 >> w;

	n = s1.length();
    k = s2.length();
	m = w.length();

	int hw = my_hash(w);
	int hs1 = my_hash(s1.substr(0, m));
    int hs2 = my_hash(s2.substr(0, m));
	int pm = 1;
	for (int i = 0; i < m-1; i++)
		pm = pm * p;

	for (int i = 0; i <= n - m; i++) {
		if (hs1 == hw && hs2 == hw) {
			cnt++;
		}
		if (i < n - m){
			hs1 = (hs1 - pm * s1[i]) * p + s1[i + m];
            hs2 = (hs2 - pm * s2[i]) * p + s2[i + m];
        }
	}
	cout << cnt;

	return 0;
}



