#include <iostream>
#include <deque>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        deque<int> q;
        q.push_front(a);
        if (a != 1)
            q.push_front(a - 1);
        for(int j = a - 1; j >= 2; j--)
        {
            for (int k = 1; k <= j; k++)
            {
                q.push_front(q.back());
                q.pop_back();
            }
            q.push_front(j - 1);

        }
        q.push_front(q.back());
        q.pop_back();
        for(auto it = q.begin(); it != q.end(); it++)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }
    return 0;
}