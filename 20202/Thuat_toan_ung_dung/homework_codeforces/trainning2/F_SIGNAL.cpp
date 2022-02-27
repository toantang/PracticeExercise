#include <iostream>
#define MAX 200000

using namespace std;
int n;
int b;
int a[MAX];
int ans = -1;

int leftTop[MAX];
int rightTop[MAX];


void solution() {
	leftTop[0] = a[0];
	for (int i = 1; i < n; ++i) {
		leftTop[i] = max(leftTop[i - 1], a[i]);
	}
	
	rightTop[n-1] = a[n-1];
	for (int i = n-2; i >= 0; --i) {
		rightTop[i] = max(rightTop[i + 1], a[i]);
	}
	for (int i = 1; i < n-1; ++i) {
		if (leftTop[i - 1] - a[i] >= b && rightTop[i + 1] - a[i] >= b) {
			ans = max(ans, leftTop[i - 1] + rightTop[i + 1] - 2 * a[i]);
		}
	}
}
int main() {
	cin >> n;
	cin >> b;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	solution();
	cout << ans << endl;
	return 0;
}