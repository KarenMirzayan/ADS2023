#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,
    cnt = 0; 
    cin >> n;
    int a[n][n]; 
    queue <int> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int source, destination; 
    cin >> source >> destination;
    source--; 
    destination--;

    if(source == destination){
        cout << 0;
        return 0; 
    }

    q.push(source);
    vector <bool> saw(n);
    saw[source] = true;
    while(!q.empty()){
        int current = q.front();
        cnt++;
        q.pop();
        for(int i = 0; i < n; i++){
            if(!saw[i] && a[current][i]){
                if(i == destination){
                    cout << cnt;
                    return 0;
                }
                saw[i] = true;
                q.push(i);
            }
        }
    }
    cout << -1;
    return 0;
}