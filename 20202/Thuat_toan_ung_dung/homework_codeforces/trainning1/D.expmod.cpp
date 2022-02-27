#include <iostream>
#define m 1000000007
using namespace std;

int modPrime(long long a, long long b)
{
    long ret = 1;
    long long x = a%m;
    long long y = y%(m-1);
    while (b > 0)
    {
        if (b % 2 > 0)
            ret = ret * a % m;
        a = a * a % m;
        b /= 2;
    }
    return (int) ret;
}

int main()
{
    long long a; long long b;
    cin >> a >> b;
    cout << modPrime(a, b) << endl;
    return 0;
}
