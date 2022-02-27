#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b)
{
    while(a != b){
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}
int main() {
    //cout << "ho ten: Tang The Toan" << endl;
    //cout << "MSSV: 20183998" << endl;
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
