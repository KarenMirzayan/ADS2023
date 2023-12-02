#include <iostream>
#include <vector>
using namespace std;

int kmp(string s, string pat) {
    int cnt = 0;
    int n = s.length();
    int m = pat.length();
    vector<int> p(n, 0);

    for(int i = 1; i < n; i++) {
        int j = p[i-1];
        while(j > 0 && s[j] != s[i]) 
            j = p[j-1];
        if (s[j] == s[i]) {
            j++;
        }
        p[i] = j;
        if(p[i] == m){
            return n - i - 1;
        }
    }
    return -1;
}

int main() {
    string a, b;
    cin >> a >> b;
    string s = b + "#" + a + a;
    cout << kmp(s, b);
}