#include <iostream>
#define MAX 1003
using namespace std;

int m; // so test case
int n; // so chieu cua vecto
int x[MAX];
int y[MAX];
int visited[MAX];
int f = 0;
int ans = INT_MAX;
int val[MAX];
int cmin = INT_MAX;
int Smin = 0;
int sumX = 0;

int testcase[MAX];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		sumX += x[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> y[i];
		if (cmin > y[i]) {
			cmin = y[i];
		}
	}

	Smin = cmin * sumX;

}

void updateBest() {
	if (f < ans) {
		ans = f;
	}
}
bool check(int v, int k) {
	if (visited[v] == 0) {
		return true;
	}
	return false;
}
void TRY(int k) {
	for (int v = 1; v <= n; v++) {
		if (check(v, k)) {
			visited[v] = 1;
			f += y[v] * x[k];
			Smin -= cmin * x[k];

			if (k == n) {
				updateBest();
			}
			else {
				if (f <= Smin) {
					TRY(k + 1);
				}
				
			}

			Smin += cmin * x[k];
			f -= y[v] * x[k];
			visited[v] = 0;
		}
	}
}
int main() {
	cin >> m;
	for (int i = 1; i <= m; i++) {
		n = 0;
		ans = INT_MAX;
		f = 0;
		input();
		for (int i = 0; i <= n; i++) {
			visited[i] = 0;
		}

		TRY(1);
		testcase[i] = ans;
	}

	for (int i = 1; i <= m; i++) {
		cout << "Case #" << i << ": " << testcase[i] << endl;
	}
	return 0;
}