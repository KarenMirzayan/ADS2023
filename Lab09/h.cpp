#include <iostream>
#include <vector>
using namespace std;

int kmp(string s) {
    int cnt = 0;
    int n = s.length();
    vector<int> p(n, 0);
    for(int i = 1; i < n - 1; i++) {
        int j = p[i-1];
        while(j > 0 && s[j] != s[i]) 
            j = p[j-1];
        if (s[j] == s[i]) 
            p[i] = j + 1;
        if((i + 1) % (i + 1 - p[i]) == 0 && (i + 1)/(i + 1 - p[i]) % 2 == 0)
            cnt++;
    }
    return cnt;
}

int main() {
    string s;
    cin >> s;
    cout << kmp(s);
    return 0;
}