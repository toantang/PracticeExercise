#include <iostream>
#define MAX 100

using namespace std;

int n;
int S0[MAX];
int S1[MAX];
int a[MAX];
bool solved0[MAX]; //solved[i] = true neu tong chan ton tai
bool solved1[MAX]; //solved[i[ = true neu tong le ton tai

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void solve() {
	int ans;
	if (a[1] % 2 == 0) {
		solved0[1] = true;
		solved1[1] = false;
		S0[1] = a[1];
	}
	else {
		S1[1] = a[1];
		solved0[1] = false;
		solved1[1] = true;
	}

	for (int i = 2; i <= n; i++) {
		if (a[i] % 2 == 0) {
			if (solved0[i - 1] == true) {
				S0[i] == max(a[i], a[i] + S0[i - 1]);
			}
			else {
				S0[i] = a[i];
			}
			solved0[i] = true;

			if (solved1[i - 1]) {
				S1[i] = S1[i - 1] + a[i];
				solved1[i] = true;
			}
			else {
				solved1[i] = false;
			}
		}
		else {
			if (solved1[i - 1] == true) {
				S1[i] = S1[i-1] + a[i];
				solved0[i] = true;
			}
			else {
				solved0[i] = false;
			}
			if (solved0[i - 1]){
				S1[i] = max(a[i], a[i] + S0[i - 1]);
			}
			else {
				S1[i] = a[i];
			}
			solved1[i] = true;
		}
	}
}



int main() {

}