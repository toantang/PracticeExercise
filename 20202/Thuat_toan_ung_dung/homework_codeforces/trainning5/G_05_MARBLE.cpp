#include <bits/stdc++.h>
#define MAX 205
using namespace std;

int W;
int H;
int n;
int w[MAX];
int h[MAX];
int dp[MAX][MAX];

void input() {
    cin >> W >> H;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> h[i];
    }
}

void solution() {
    for (int i = 1; i <= W; i++) 
    {
        for (int j = 1; j <= H; j++) 
        {
            dp[i][j] = i * j;
            for (int k = 1; k <= n; k++) 
            {
                if (i == w[k] && j == h[k]) 
                {
                    dp[i][j] = 0;
                    break;
                }
            }

            for (int k = 1; k < i; k++) 
            {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]);
            }
            for (int k = 1; k < j; k++) 
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]);
            }
        }
    }
}
int main() {
    input();
    solution();
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = sum + dp[1][i];
    }
    cout << sum << endl;
    return 0;
}