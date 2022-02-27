#include <iostream>
#include <stdio.h>
#define MAX 1000003
using namespace std;

int n;
int a[MAX];

int cnt1 = 0, cnt2 = 0, ans1 = 0;
int cnt3 = 0, cnt4 = 0, ans2 = 0;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void printSolution(int start, int end) {
	for (int i = start; i < end; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void solution() {
	for (int i = 2; i < n; i++) {
		if (a[i] > a[i - 1]) {
			cnt1++;
		}
		if (a[i] > a[i + 1]) {
			cnt2++;
		}
		if ((a[i] <= a[i + 1] && a[i] <= a[i - 1]) || i == (n-1)) {
			int f1 = min(cnt1, cnt2);
			ans1 = max(f1, ans1);
			cnt1 = 0; 
			cnt2 = 0;
		}
	}

	for (int i = 2; i < n; i++) {
		if (a[i] < a[i - 1]) {
			cnt3++;
		}
		if (a[i] < a[i + 1]) {
			cnt4++;
		}
		if ((a[i] >= a[i - 1] && a[i] >= a[i + 1]) || i == n - 1) {
			int f2 = min(cnt3, cnt4);
			ans2 = max(f2, ans2);
			cnt3 = 0;
			cnt4 = 0;
		}
	}
}
int main() {
	input();
	solution();
	printf("%d %d", ans1, ans2);
	return 0;
}