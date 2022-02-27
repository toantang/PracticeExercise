#include <bits/stdc++.h>

using namespace std;

const int c[5] = {0, 2, 4, 3, 5};
int a[6];
bool visited[6];
int f = 0;
int ans = 0;

bool check(int v, int k, int n) {
    if (c[k] * v + f <= n) {
        return true;
    }
    return false;
}

void solution(int n) {
    for (int i = 1; i <= 5; i++) {
        a[1] = i;
        a[2] = 6 - i;
        int currentSum = 0;
        currentSum = c[1] * a[1] + c[2] * a[2];
       // cout << "a[1] = " << a[1] << ", a[2] = " << a[2] << ", currentSum = " << currentSum << endl;
        for (int j = 1; j <= (n-currentSum)/c[3]; j++) {
            a[3] = j;
            currentSum += c[3] * a[3];
            //cout << "   a[3] = " << a[3] << ", currentSum = " << currentSum << endl;
            for (int k = 1; k <= (n-currentSum)/c[4]; k++) {
                a[4] = k;
                currentSum += c[4] * a[4];
                //cout << "       a[4] = " << a[4] << ", currentSum = " << currentSum << endl;
                if (currentSum == n) {
                    ans++;
                }

                currentSum -= c[4] * a[4];
            }

            currentSum -= c[3] * a[3];
        }
    }
}

int fx(int n){

    if(n <= 1) return 1;

    if(n%2 == 0) return 3*fx(n-1) + 2*fx(n-2);

    else return 2*fx(n-1) + 3*fx(n-2);

}

int main() {
    //solution(60);
    //cout << "ans = " << ans << endl;
    cout << fx(5) << endl;
    return 0;
}