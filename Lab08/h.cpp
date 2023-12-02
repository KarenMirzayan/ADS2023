#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7, siz = 1e5;
int a[siz];


string LCS(vector <string> &v){
    a[siz] = {0};
    int maxi = 0, mini;
    ll res = 0;

    for(int i = 0; i < v[1].size(); i++){

        res = v[1][i] - 'a' + 1;
        ll minres = 0;

        for(int j = v[0].size() - 1; j >= 0; j--){
            minres = v[0][j] - 'a' + 1;

            if(res == minres){
                a[j + 1] = a[j] + 1;
            }

            else{
                a[j + 1] = 0;
            }
            if(a[j + 1] > maxi){
                maxi = a[j + 1];
                mini = j + 1 - maxi;
            }
        }
        for(int k = 0; k <= v[0].size(); k++) {
                cout << a[k] << " ";
            }
            cout << "||" << mini << " " << maxi << endl;
    }
    if(maxi == 0) return "";
    return v[0].substr(mini, maxi);
}


int main(){
    int n;
    cin >> n;
    string s, ss; 
    cin >> s;
    for(int i = 0; i < n - 1; i++){
        vector <string> v;
        cin >> ss;
        v.push_back(s);
        v.push_back(ss);
        s = LCS(v);
    }
    cout << s;
}