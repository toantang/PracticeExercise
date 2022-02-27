#include <iostream>
#define MAX 100

using namespace std;

int n;
int c[MAX][MAX];

string bin(unsigned n) {
	string s = "";
	for (int i = 10; i >= 0; i--) {
		int b = S & (1 << i);
		if (b == 1) {
			s += 1;
		}
		else{
			s += "0";
		}
	}

	return s;
}

unsigned int addElement(unsigned int S, int x) {
	return S | (1 << x);
}

unsigned int removeElement(unsigned int S, int x) {
	return S & (~(1 << x));
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}
}

int TSP(int i, unsigned int S) {

}
int main() {
	memset(F, -1, sizeof(F));
	return 0;
}