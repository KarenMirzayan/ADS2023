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
    bool f = false;
    cin >> n;
    int c = 0, b = 0;
    while (b != n) {
        i++;
        if (isPrime(i)) {
            c++;
            f = true;
        }
        if (f && isPrime(c)) {
            f = false;
            b++;
        }
    }
    cout << i;
}