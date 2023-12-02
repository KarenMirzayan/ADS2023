#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    queue<char> q;
    int cnt_K = 0, cnt_S = 0, ost_K = 0, ost_S = 0, pts_K = 0, pts_S = 0;
    for(int i = 0; i < s.size(); i++){
        q.push(s[i]);
        if(s[i] == 'K'){
        ost_K++;
        }
        else{
        ost_S++;
    }
    }
    bool running = true;
    while(running) {
        if(q.front() == 'S'){
            if(cnt_K >= 1){
                cnt_K--;
                q.pop();
                ost_S--;
            }
            else{
                q.push('S');
                q.pop();
                cnt_S++;
                pts_S++;
            }
        }
        else{
            if(cnt_S >= 1){
                cnt_S--;
                q.pop();
                ost_K--;
            }
            else{
                q.push('K');
                q.pop();
                cnt_K++;
                pts_K++;
            }
        }
        if(ost_K <= 0 || ost_S <= 0){
            if(pts_K > pts_S){
                cout << "KATSURAGI";
                return 0;
            }
            else{
                cout << "SAKAYANAGI";
                return 0;
            }
        }
    }
}