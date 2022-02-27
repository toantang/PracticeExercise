#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    long long m = 1e9 + 7;
    cin >> a >> b;
    long long y = (a%m)+ (b%m);
    y = y%m;
    cout << y << endl;
    return 0;
}
