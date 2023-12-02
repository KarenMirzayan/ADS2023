#include <iostream>
#include <unordered_set>
using namespace std;

long long p=31;

int main(){
    string s;
    cin >> s;

    long long n =  s.length();
    unordered_set <long long> us;

    for (long long i=0; i<n; i++){
        string temp="";
        long long h=0;

        for (long long j=i; j<n; j++){
            h = h * p + s[j];
            us.insert(h);
        }
    }
    cout << us.size();
    return 0;
}