#include <iostream>
#define MAX 100

using namespace std;

int n; // n hanh khach
int m; // so luong hanh khach toi da
int c[MAX][MAX]; // ma tran khoang cach duong di
int visited[MAX]; // dinh thu i da dc tham hay chua
int f; // tong duong di hien tai
int ans = INT_MAX; // kqua cua bai toan
int x[MAX]; // mang truy vet danh dau
int currentCustom[MAX]; // so hanh khach hien tai tại thời điểm thứ i
int bring[MAX]; // so mang lwu tru trang thai các hành khách ( đã dc đón hay chưa)
int pay[MAX]; // hành khách thứ i đã được trả về đúng điểm hay chưa
int cmin;
int cnt = 1;

void input() {
	cin >> n >> m;
	for (int i = 0; i <= 2 * n; i++) {
		for (int j = 0; j <= 2 * n; j++) {
			cin >> c[i][j];
			if (c[i][j] < cmin && c[i][j] != 0) {
				cmin = c[i][j];
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		visited[i] = 0;
		bring[i] = 0;
		pay[i] = 0;
		currentCustom[i] = 0;
	}

	visited[0] = 1;
	bring[0] = 1;
	pay[0] = 1;
	x[0] = 0;
}

void output() {
	for (int i = 0; i <= 2*n; i++) {
		cout << x[i] << " ";
	}

	cout << endl;
	cout << "currentCustom = ";
	for (int i = 0; i <= 2*n; i++) {
		cout << currentCustom[i] << " "; 
	}
	cout << endl;
	cout << "pay = ";
	for (int i = 0; i <= n; i++) {
		cout << pay[i] << " ";
	}
}

bool check(int v, int k) {
	if (visited[v] == 0) {
		if (v < n) {
			return true;
		}
		else {
			if (bring[v - n] != 1) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	return false;
}

void updateBest() {
	if (f + c[x[2 * n]][x[0]] < ans) {
		ans = f + c[x[2 * n]][x[0]];
	}
}

bool canUpdate() {
	for (int i = 1; i <= n; i++) {
		if (pay[i] == 0) {
			return false;
		}
	}
	return true;
}
void TRY(int k) {
	for (int v = 1; v <= (2*n); v++) {
		if (check(v, k)) {
			visited[v] = 1;
			x[k] = v;
			f += c[x[k-1]][x[k]];

			//cap nhat trang thai hanh khach
			if (v <= n) {
				if (currentCustom[k - 1] < m) {
					currentCustom[k] = currentCustom[k - 1] + 1;
					bring[v] = 1;
				}
				else {
					currentCustom[k] = currentCustom[k - 1];
				}
			}
			else {
				if (bring[v - n] == 1 && currentCustom[k - 1] > 0) {
					currentCustom[k] = currentCustom[k - 1] - 1;
					pay[v - n] = 1;
				}
				else {
					currentCustom[k] = currentCustom[k - 1];
				}
			}

			if (k == (2 * n)) {
				updateBest();
				/*output();
				cout << "ans = " << ans << endl;
				cout << endl;
				cout << "===============================================" << endl;*/
			}
			else {
				if (f + cmin * (n - k + 1) < ans) {
					TRY(k + 1);
				}
			}

			//cap nhat trang thai ban dau
			if (v <= n) {
				if (currentCustom[k - 1] < k) {
					bring[v] = 0;
				}
			}
			else {
				if (currentCustom[k - 1] > 0) {
					pay[v-n] = 0;
				}
			}
			
			f -= c[x[k-1]][x[k]];
			currentCustom[k] = 0;
			visited[v] = 0;
		}
	}
}
int main() {
	input();
	TRY(1);
	cout << ans << endl;
	return 0;
}