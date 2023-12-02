#include <iostream>
#include <vector>
using namespace std;

#define ll unsigned long long

string antiHash(vector <ll> &v){
    ll p = 1;
    string str = "";
    for(int i = 0; i < v.size(); i++){
        if(i == 0) str += ((v[i] / p) + 97);
        else str += (((v[i] - v[i - 1]) / p) + 97);
        p = p*2;
    }
    return str;
}

int main(){
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << antiHash(v);
}