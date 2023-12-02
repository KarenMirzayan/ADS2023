#include <iostream>
#include <vector>
using namespace std;

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
	cin >> s;
	cin >> n;
	int strLen = s.length();
	vector<pair<char, bool>> v;
	for(int i = 0; i < strLen; i++) {
		v.push_back(pair(s[i], false));
	}
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;

		int patLen = a.length();
		int hashPat = my_hash(a);
		int hashStr = my_hash(s.substr(0, patLen));
		int pm = 1;

		for(int j = 0; j < patLen - 1; j++)
			pm *= p;
		
		for(int j = 0; j <= strLen - patLen; j++) {
			if(hashPat == hashStr) {
				for(int k = j; k < j + patLen; k++) {
					v[k].second = true;
				}
			}
			if (j < strLen - patLen) {
				hashStr = (hashStr - pm * s[j]) * p + s[j + patLen];
			}
		}
	}
	for (auto &i: v) {
		if(i.second == false) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}