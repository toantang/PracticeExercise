#include <bits/stdc++.h>

using namespace std;

void solution(int a[], int N, int M) {
    int low, high, mid;
    low = 0, high = N - 1;
    int ans = INT_MAX;

    sort(a, a + N);
    while(low < high) {
        mid = (low + high)/2;
        int sum = 0;
        for (int i = mid; i <= high; i++) {
            sum += a[i] - a[mid];
        }
        cout << "mid = " << mid << ", sum = " << sum << endl;
        if (sum > M) {
            low = mid+1;
            ans = a[mid];
        }
        else if (sum < M) {
            high = mid;
            
        }
        else {
            ans = a[mid];
            break;
        }
    }

    cout << ans << endl;

}
int main() {
    int N, M, H;
    cin >> N >> M;
    int a[N+1];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    solution(a, N, M);
    return 0;
}