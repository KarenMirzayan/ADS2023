#include <iostream>
#include <vector>
#include <map>
using namespace std;

pair<string, int> kmp(string s, string pat) {
    int n = s.length();
    int m = pat.length();
    int max = 0;
    vector<int> p(n, 0);

    for(int i = 1; i < n; i++) {
        int j = p[i-1];
        while(j > 0 && s[j] != s[i]) 
            j = p[j-1];
        if (s[j] == s[i]) 
            j++;
        p[i] = j;
    }
    return make_pair(pat, p[s.length() - 1]);
}

int main() {
    string a;
    int n, max = 0, cnt = 0;
    cin >> a >> n;
    char c = tolower(a[0]);
    a = c + a.substr(1);
    map<string, int> m;
    vector<string> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        char c = tolower(v[i][0]);
        v[i] = c + v[i].substr(1);
        string s = v[i] + '#' + a;
        pair<string, int> p = kmp(s, v[i]);
        if (p.second > max)
            max = p.second;
        m.insert(p);
    }
    if (max == 0) {
        cout << 0;
        return 0;
    }
    for(auto &i: v) {
        if (m[i] == max) {
            cnt++;
        }
    }
    cout << cnt << endl;
    for(auto &i: v) {
        if (m[i] == max) {
            char c = toupper(i[0]);
            i = c + i.substr(1);
            cout << i << endl;
        }
    }
}