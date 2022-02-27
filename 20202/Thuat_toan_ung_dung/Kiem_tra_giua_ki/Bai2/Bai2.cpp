#include <iostream>
#include <algorithm>
#define MAX 15
using namespace std;

int n; // co n mon hoc
int a[MAX];
int ans = 99999;
int x[MAX]; // mang luu tru cac ngay
int f = 0; // so ngay hien tai
int visited[MAX];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		visited[i] = 0;
	}

	f = n;
}

int k = 1;
void solution() {
	for (int i = n; i >= 2; i--) {
		if (visited[i] == 0) {
			k = i;
			visited[k] = 1;
			for (int j = i - 1; j >= 1; j--) {
				if (a[k] + a[j] <= 6 && visited[j] == 0) {
					a[k] += a[j];
					f -= 1;
					visited[j] = 1;
				}
			}
		}
	}
}
int main() {
	input();
	sort(a, a + n);
	solution();
	cout << f << endl;
	return 0;
}