#include <iostream>
#include <vector>
using namespace std;

vector<int> kmp(string s) {
    int cnt = 0;
    int n = s.length();
    vector<int> p(n, 0);
    for(int i = 1; i < n; i++) {
        int j = p[i-1];
        while(j > 0 && s[j] != s[i]) 
            j = p[j-1];
        if (s[j] == s[i]) 
            j++;
        p[i] = j;
    }
    return p;
}

int main() {
    string s;
    cin >> s;
    vector<int> v = kmp(s);
    cout << s.length() - v.back();
    return 0;
}