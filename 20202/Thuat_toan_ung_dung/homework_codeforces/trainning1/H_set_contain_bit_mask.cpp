#include <iostream>
#include <string>
#define MAX 31

using namespace std;

string bin(unsigned int n)
{
    string s = " ";
    for (int d = 0; d < 31; d++)
    {
        int i = 1 << d;
        if (n & i) {
            s = s + "1";
        }
        else {
            s = s + "0";
        }
    }
    return s;
}

int contain(string x, string y)
{
    for (int i = 0; i < 31; i++) {
        if ((x[i] == '0') && (y[i] == '1')) {
            return 0;
            break;
        }
    }
    return 1;
}
int main()
{
    int n, m, a[MAX], b[MAX];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int x = 1 << a[0];
    for (int i = 1; i < n; i++) {
        x = x | (1 << a[i]);
    }
    int y = 1 << b[0];
    for (int i = 1; i < m; i++) {
        y = y | (1 << b[i]);
    }

    cout << contain(bin(x), bin(y)) << endl;
    return 0;
}
