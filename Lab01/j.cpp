#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;
    while(true) {
        char a;
        int n;
        cin >> a;
        if (a != '!' && a != '*')
            cin >> n;
        else if (a == '*')
        {
            if(d.size() <= 0)
                cout << "error\n";
            else {
                cout << d.front() + d.back() << "\n";
                d.pop_back();
                if (d.size() > 0)
                    d.pop_front();
            }
        }
        else
            break;
        if (a == '+')
        {
            d.emplace_front(n);
        }
        else if (a == '-')
        {
            d.emplace_back(n);
        }
        // for (auto it = d.begin(); it != d.end(); ++it)
        //     cout << *it;
        // cout << "\n";
    }
    return 0;
}