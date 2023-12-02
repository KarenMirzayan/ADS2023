#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main(){
    queue<int> Boris;
    queue<int> Nuris;
    for(int i = 0; i < 5; i++)
    {
        int a;
        cin >> a;
        Boris.emplace(a);
    }
    for(int i = 0; i < 5; i++)
    {
        int a;
        cin >> a;
        Nuris.emplace(a);
    }
    int c = 0;
    while(!Boris.empty() && !Nuris.empty() && c <= pow(10, 6))
    {
        if(Boris.front() == 0 && Nuris.front() == 9)
        {
            Boris.push(Boris.front());
            Boris.push(Nuris.front());
            Nuris.pop();
            Boris.pop();
        }
        else if(Boris.front() == 9 && Nuris.front() == 0)
        {
            Nuris.push(Boris.front());
            Nuris.push(Nuris.front());
            Nuris.pop();
            Boris.pop();
        }
        else if(Boris.front() > Nuris.front())
        {
            Boris.push(Boris.front());
            Boris.push(Nuris.front());
            Nuris.pop();
            Boris.pop();
        }
        else if(Boris.front() < Nuris.front())
        {
            Nuris.push(Boris.front());
            Nuris.push(Nuris.front());
            Nuris.pop();
            Boris.pop();
        }
        c++;
    }
    if(Boris.empty()) cout << "Nursik " << c;
    else if(Nuris.empty()) cout << "Boris " << c;
    else if(c >= pow(10, 6)) cout << "blin nichya";
    return 0;
}