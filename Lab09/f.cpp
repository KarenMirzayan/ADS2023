#include <iostream>
#include <vector>
using namespace std;

pair<vector<int>, int> kmp(string s, string pat) {
    int cnt = 0;
    int m = pat.length();
    string a = pat + '#' + s;
    int k = a.length();
    vector<int> p(k, 0);
    vector<int> v;
    for(int i = 1; i < k; i++) {
        int j = p[i-1];
        while(j > 0 && a[j] != a[i]) 
            j = p[j-1];
        if (a[j] == a[i]) 
            j++;
        p[i] = j;
        if(p[i] == m) {
            v.push_back(i-2*m + 1);
            cnt++;
        }
    }
    return pair(v, cnt);
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    pair<vector<int>, int> p = kmp(text, pattern);
    cout << p.second << endl;
    for(int i = 0; i < p.first.size(); i++) {
        cout << p.first[i] << " ";
    }
}