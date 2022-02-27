#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100

using namespace std;

int n; // n khoa hoc
int m; // m giang vien
int load[MAX]; // so khoa hoc phai day cua giao vien i
int ans;
int teach[MAX][MAX]; // giang vien i day duoc mon j
//int cant_assign[MAX][MAX]; // môn u có trùng lịch với môn v hay ko
int conflict[MAX][MAX]; // courses i xung đột với môn j

int current_teach[MAX][MAX];

// kiem tra xem load cua giao vien p co lon hon load giao vien q
bool cmp(int p, int q) {
	if (load[p] > load[q]) {
		return true;
	}
	return false;
}

bool conflictCourses(int v, int k) {
	for (int i = 1; i <= n; i++) {
		if (conflict[current_teach[v][i]][k] == 1) {
			return false;
		}
	}
	return true;
}
bool check(int v, int k) {
	if (teach[v][k] == 1 && conflictCourses(v, k)) {
		return true;
	}
}

void updateBest() {
	int maxLoad = INT_MIN;
	for (int i = 1; i <= n; i++) {
		if (maxLoad < load[i]) {
			maxLoad = load[i];
		}
	}

	ans = min(ans, maxLoad);
}

void TRY(int k) {
	for (int v = 1; v <= m; v++) {
		if (check(v, k)) {
			load[v] += 1;
			current_teach[v][k] = k;
			if (k == n) {
				updateBest();
			}
			else {
				TRY(k + 1);
			}

			load[v] -= 1;
			current_teach[v][k] = 0;
		}
	}
}

int main() {
	
	cin >> m >> n;
	for (int j = 1; j <= m; j++) {
		int k;
		cin >> k;
		while (k--) {
			int p;
			cin >> p;
			teach[j][p] = 1;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int p1, p2;
		cin >> p1 >> p2;
		if (p1 > p2) {
			swap(p1, p2);
		}
		conflict[p1][p2] = 1;
	}
	ans = INT_MAX;
	for (int i = 1; i <= n; i++) {
		load[i] = 0;
	}
	TRY(1);
	cout << ans << endl;
	return 0;
}