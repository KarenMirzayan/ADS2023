#include <iostream>
#include <vector>
using namespace std;

vector<int> kmp(string s) {
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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        string s;
        cin >> s >> k;
        vector<int> v = kmp(s);
        int result = s.length() - v[v.size() - 1];
        cout << result * (k - 1) + s.length() << endl;
    }
}