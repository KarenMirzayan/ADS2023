#include <iostream>
#include <climits>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, max = INT_MIN, cnt = 0;
    vector<int> v;
    cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        if (m[k]){
            m[k] += 1;
        }
        else
            m[k] = 1;
    }
    for(auto &it: m){
        if(it.second > max) {
            v.clear();
            max = it.second;
            v.push_back(it.first);
        }
        else if (it.second == max){
            v.push_back(it.first);
        }
    }
    sort(v.rbegin(), v.rend());
    for(auto &il: v){
        cout << il << " ";
    }
}
