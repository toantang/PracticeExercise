#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int best = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = max(a[i], sum + a[i]);
        best = max(sum, best);
    }
    cout << best;
    return 0;
}
