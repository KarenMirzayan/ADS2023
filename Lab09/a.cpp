#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int myHash(char a) {
    return (int)(a-'a' + 1);
}

bool kmp(string s, int m) {
    int n = s.length();
    vector<int> p(n, 0);
    for(int i = 1; i < n; i++) {
        int j = p[i-1];
        while(j > 0 && s[j] != s[i]) 
            j = p[j-1];
        if (s[j] == s[i]) 
            j++;
        p[i] = j;
        if (p[i] == m) {
            return true;
        }
    }
    return false;
}

int main() {
    string a, b;
    cin >> a >> b;
    string s = b + "#" + a;
    bool t = false;
    int cnt = 1;
    while(s.length() - b.length() - 1 < b.length()){
        s += a; 
        cnt++;
    }
    if (kmp(s, b.length()) == true) {
        cout << cnt;
    }
    else if (kmp(s + a, b.length()) == true) {
        cout << cnt + 1;
    }
    else {
        cout << -1;
    }
    return 0;
}