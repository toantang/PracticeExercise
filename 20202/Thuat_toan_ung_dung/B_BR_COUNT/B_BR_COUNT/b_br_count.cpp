#include <iostream>
#include <stack>
#define MAX 1003
using namespace std;

int n; // kich thuoc cua xau S
string s;
int a[MAX];
int c[2] = {-1, 1};
int ans;
int sum; // tong cua string khi da chuyen qua day so 0 1

void input() {
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			a[i] = 1;
		}
		else if (s[i] == ')'){
			a[i] = -1;
		}
		else {
			a[i] = 0;
		}
	}
}

void TRY(int k) {
	if (k == n) {
		if (sum == 0) {
			ans++;
		}
	}
	else {
		if (sum >= 0) {
			if (a[k] == 0) {
				for (int i = 0; i <= 1; i++) {
					a[k] = c[i];
					sum += c[i];
					
					if (sum >= 0) {
						TRY(k + 1);
					}

					sum -= c[i];
					a[k] = 0;
				}
			}
			else {
				if (a[k] == 1) {
					sum += 1;
					if (sum >= 0) {
						TRY(k + 1);
					}
					sum -= 1;
				}
				else {
					sum -= 1;
					if (sum >= 0) {
						TRY(k + 1);
					}
					sum += 1;
				}
			}
		}
	}
}


int main() {
	input();
	TRY(0);
	cout << ans << endl;
	return 0;
}