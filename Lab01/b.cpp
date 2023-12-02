#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b[0] = -1;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if(j == 0 && a[0] > a[i])
            {
                b[i] = -1;
                break;
            }
            if(a[i] >= a[j])
            {
                b[i] = a[j];
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}