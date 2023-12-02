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
    int n;
    string s;
    cin >> s >> n;
    int strLen = s.length();
    for(int i = 0; i < n; i++) {
        int l, r, cnt = 0;
        cin >> l >> r;
        l--;
        r--;
        string a = s.substr(l, r - l + 1);
        int patLen = a.length();

        int hashPat = my_hash(a);
        int hashStr = my_hash(s.substr(0, patLen));
        int pm = 1;
        for(int j = 0; j < patLen-1; j++) {
            pm *= p;
        }
        for(int j = 0; j <= strLen - patLen; j++) {
            if(hashStr == hashPat) cnt++;
            if (j < strLen - patLen)
			    hashStr = (hashStr - pm * s[j]) * p + s[j + patLen];
        }
        cout << cnt << endl;
    }
	return 0;
}



