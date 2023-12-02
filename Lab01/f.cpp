#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n)
{
    if(n<=1)
        return false;
    else
    {
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}
int main() {
    int n, i = 0;
    cin >> n;
    int c = 0;
    while (c != n) {
        i++;
        if (isPrime(i)) c++;
    }
    cout << i;
}