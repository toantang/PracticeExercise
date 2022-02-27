#include <iostream>

using namespace std;

int lucas(int n)
{
    if (n == 0) {
        return 2;
    }
    if (n == 1) {
        return 1;
    }
    return lucas(n-1) + lucas(n-2);
}
int main()
{
    //cout << "ho ten: Tang The Toan" << endl;
    //cout << "MSSV: 20183998" << endl;
    int n;
    cin >> n;
    cout << lucas(n) << endl;
    return 0;
}
