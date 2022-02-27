#include <iostream>
#define MAX 1000000

using namespace std;

int memory[MAX];
bool solved[MAX]; //solved[i] = true, bai toan con doi voi i da dc giai
int a[MAX];
int n;

int S(int i) {
	if (i == 1) {
		memory[i] = a[i];
		return a[i];
	}
	else {
		if (solved[i] == false) {
			memory[i] = max(S(i - 1) + a[i], a[i]);

		}
	}
	solved[i] = true; // bai toan con doi voi i da dc giai
	return memory[i];
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		solved[i] = false;
	}
}
int main() {
	cout << "fasdjkg";
	return 0;
}