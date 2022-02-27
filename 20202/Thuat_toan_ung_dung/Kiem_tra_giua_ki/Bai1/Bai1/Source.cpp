#include <bits/stdc++.h>
#define MAX 10

using namespace std;

const int x = pow(10, 5); //he so cua C
const int y = pow(10, 4) + pow(10, 3) + pow(10, 2) + 1; //he so cua T
const int z = pow(10, 3) + 1; // he so cua D
const int t = pow(10, 2); // he so cua L
const int m = 10; // he so cua U
const int q = 10; // he so cua G

int n; // so n
int ans; // so cach
int a[MAX];
int sum = 0; // tong cua phep tinh hien 
int visited[MAX];

void input() {
	cin >> n;
}

void updateSum(int v, int k) {
	if (k == 1) {
		sum += v * x;
	}
	else if (k == 2) {
		sum += v * y;
	}
	else if(k == 3) {
		sum += v * z;
	}
	else if(k == 4) {
		sum += v * t;
	}
	else if (k == 5) {
		sum += v * m;
	}
	else {
		sum += v * q;
	}
}

void defaultSum(int v, int k) {
	if (k == 1) {
		sum -= v * x;
	}
	else if (k == 2) {
		sum -= v * y;
	}
	else if (k == 3) {
		sum -= v * z;
	}
	else if (k == 4) {
		sum -= v * t;
	}
	else if (k == 5) {
		sum -= v * m;
	}
	else {
		sum -= v * q;
	}
}

bool check(int v, int k) {
	if (k == 1) {
		if (v >= 1 && v >= n/x - 1 && v <= n/x) {
			return true;
		}
	}
	else if (k == 2) {
		if (v >= 1 && v <= (n - sum) / y) {
			return true;
		}
	}
	else if (k == 3) {
		if (v <= (n - sum) / z) {
			return true;
		}
	}
	else if (k == 4) {
		if (v <= (n - sum) / t) {
			return true;
		}
	}
	else if (k == 5) {
		if (v <= (n - sum) / m) {
			return true;
		}
	}
	else if (k == 6) {
		if (v <= (n - sum) / q) {
			return true;
		}
	}
	return false;
}

bool checkSame(int v, int k) {
	if (visited[v] == 0) {
		return true;
	}
	else {
		return false;
	}
}
void TRY(int k) {
	for (int v = 0; v <= 9; v++) {
		if (check(v, k) && checkSame(v, k)) {
			a[k] = v;
			updateSum(v, k);
			visited[v] = 1;

			if (k == 6) {
				if (sum == n) {
					ans++;
					/*for (int i = 1; i <= k; i++) {
						cout << a[i] << " ";
					}
					cout << "sum = " << sum << endl;
					cout << endl;*/
				}
			}
			else {
				TRY(k + 1);
			}

			visited[v] = 0;
			defaultSum(v, k);
		}
	}
}
int main() {
	input();
	TRY(1);
	cout << ans << endl;
	return 0;
}
