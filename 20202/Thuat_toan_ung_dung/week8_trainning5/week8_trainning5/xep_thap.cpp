#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000;
int n;

struct Block {
	int x, y, z;
	bool operator < (Block& b) {
		return x < b.x&& y < b.y;
	}
}b[N];

bool cmp(Block& b1, Block& b2) {
	if (b1.x != b2.y) {
		return b1.x > b2.x;
	}
	if (b1.y != b2.y) {
		return b1.y > b2.y;
	}
	return b1.z > b2.z;
}

int main() {
	int t;
	int m; // number of Block
	while (true) {
		cin >> n;
		if (n == 0) break;
		int x[3];
		m = -1;
		cin >> x[0] >> x[1] >> x[2];
		sort(x, x + 3);
		do {
			m++;
			b[m].x = x[0];
			b[m].y = x[1];
			b[m].z = x[3];
		} while (next_permutation(x, x + 3));
	}
	sort(b, b + m, cmp);
	S[0] = b[0].z;
	int ans = S[0];
	for (int i = 1; i < m; i++) {
		S[i] = b[i].z;
		for (int j = 0; j <= i - 1; j++) {
			if (b[j] > b[i]) {
				S[i] = max(S[i], S[j] + b[j].z);
			}
		}

		ans = max(ans, S[i]);
	}
	/*for (int i = 0; i < m; i++) {
		cout << b[i].x << ", " << b[i].y << ", " << b[i].z << endl;
	}*/
	return 0;
}