#include <iostream>

#define MAX 1000005

using namespace std;

int n;
int a[MAX];
int ans = 0; // do dai day con dan dau dai nhat
int cnt = 1;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void solution() {
	for (int i = 1; i < n; i++) {
		int k = i;
		for (int j = i + 1; j <= n; j++) {
			if (a[k] * a[j] < 0 && abs(a[k]) < abs(a[j])) {
				cnt++;
				k = j;
			}
		}

		ans = max(ans, cnt);
		cnt = 0;
	}
}
int main() {
	input();
	solution();
	cout << ans << endl;
	return 0;
}