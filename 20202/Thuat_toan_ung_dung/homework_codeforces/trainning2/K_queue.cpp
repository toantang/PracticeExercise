#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int n;
int a[MAX];
int ans[MAX];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans[i] = -1;
    }
}

void solution() {
    int minFromEnd[n+1];
    minFromEnd[n] = a[n];
    for (int i = n-1; i >= 1; i--) {
        minFromEnd[i] = min(minFromEnd[i+1], a[i]);
    }

    /*for (int i = 1; i <= n; i++) {
        cout << minFromEnd[i] << " ";
    }
    cout << endl;*/

    for (int i = 1; i <= n; i++) {
        int low = i + 1, high = n, value = i;
 
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[i] > minFromEnd[mid]) {

                value = max(value, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        //cout << "i = " << i << ", value = " << value << endl;
        ans[i] = value - i - 1;
    }
}

int main() {
    input();
    solution();
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}