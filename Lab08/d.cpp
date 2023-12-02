#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
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
    while (true)
    {
        int n, max = 0, cnt = 0;
        string s;
        cin >> n;
        pair<string, int> m[n];
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            cin >> m[i].first;
            m[i].second = 0;
        }
        cin >> s;
        int strLength = s.length();
        for (auto &it: m) {
            int patLength = it.first.length();
            int hashKey = my_hash(it.first);
            int hashStr = my_hash(s.substr(0, patLength));
            int pm = 1;
            for(int j = 0; j < patLength - 1; j++) {
                pm = pm * p;
            }
            for (int j = 0; j <= strLength - patLength; j++) {
                if (hashStr == hashKey) {
                    cnt++;
                }
                if (j < strLength - patLength)
                    hashStr = (hashStr - pm * s[j]) * p + s[j + patLength];
            }
            if(cnt > max) max = cnt;
            it.second = cnt;
            cnt = 0;
        }
        cout << max << endl;
        for (auto &it: m) {
            if(it.second == max) cout << it.first << endl;
        }
    }
	return 0;
}



