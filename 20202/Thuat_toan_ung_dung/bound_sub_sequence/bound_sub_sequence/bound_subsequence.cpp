#include <iostream>
#include <time.h>
#define MAX 20003

using namespace std;

int n; // so phan tu
int m; // can duoi
int M; // can tren
int a[MAX];

int sum = 0;
int ans;

void input() {
	cin >> n >> m >> M;
	/*n = 20000;
	m = 547;
	M = 708;*/
	for (int i = 1; i <= n; i++) {
		//int r = -20000 + rand() % (20000 + 1 - (-20000));
		//a[i] = r;
		cin >> a[i];
		if (a[i] >= m && a[i] <= M) {
			ans++;
		}
	}
}

void output() {
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
}

void solution() {
	for (int i = 1; i < n; i++) {
		sum = a[i];
		for (int j = i + 1; j <= n; j++) {
			sum += a[j];
			if (sum >= m && sum <= M) {
				ans++;
			}
		}
	}
}
int main() {
	input();
	solution();
	/*output();
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	solution();
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << " cpu_time_used = " << cpu_time_used << endl;*/

	cout << ans << endl;
	return 0;
}