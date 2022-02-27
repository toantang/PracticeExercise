#include <iostream>
#include <algorithm>
#define MAX 1000

using namespace std;

int a[MAX]; // mang da cho
int n; // so phan tu cua mang
int limited; // giới hạn của tổng dãy con
int x[MAX]; // mang lưu trữ các phần tử của dãy con thỏa mãn
int visited[MAX]; // đánh dấu phần tử của mảng đã được duyệt hay chưa
int s = 0; // tổng hiện tại 

void input() {
	cin >> n >> limited;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
}

void printSolution(int k) {
	for (int i = 1; i <= k; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
bool check(int v, int k) {
	return !visited[v];
}

int cnt = 0;
void TRY() {
	for (int i = 1; i < n; i++) {
		int s = a[i];
		if (a[i] < limited) {
			cnt++;
		}
		for (int j = i; j <= n; j++) {			
			s = s + a[j];
			if (s < limited) {
				cnt++;
			}
			else {
				break;
			}
		}
	}
}
int main() {
	input();
	TRY();
	cout << cnt << endl;
	return 0;
}