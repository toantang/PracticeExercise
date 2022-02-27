#include <iostream>
#define m 1000000007

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n ;i++) {
        cin >> a[i];
    }

    unsigned long long y = 0;

    for (unsigned long long i = 0; i < n; i++) {
        y = y + a[i]%m;
        y = y%m;
    }
    cout << y << endl;
    return 0;
}
