#include <iostream>
#include <vector>
using namespace std;

bool kmp(string s, string pat, int k) {
    int cnt = 0;
    int n = s.length();
    vector<int> p(n, 0);

    for(int i = 1; i < n; i++) {
        int j = p[i-1];
        while(j > 0 && s[j] != s[i]) 
            j = p[j-1];
        if (s[j] == s[i]) {
            j++;
        }
        p[i] = j;
        if(p[i] == pat.length())
            cnt++;
        if(cnt == k) {
            return true;
        }
    }
    return false;
}

int main() {
    int k;
    string pat, password;
    cin >> pat >> k >> password;
    kmp(pat + "#" + password, pat, k) ? cout << "YES" : cout << "NO";
}