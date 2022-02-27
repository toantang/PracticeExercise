#include <iostream>
#define N 100

using namespace std;

int n, K;
int Q; // tải trọng 1 xe
int d[N];
int y[N]; // điểm giao đầu tiên cảu xe thứ k (y[k] thuộc {1, 2, ...N}, với k = 1, 2, ..., k
int x[N]; // điểm tiếp theo của điểm giao i trên lộ trình 
bool visited[N];
int load[N]; // tải trọng tích lũy trên đường đi mà ta đang xây dựng
int segments; //segments for solution if (segmenst = n + K)

void solution() {
	for (int k = 1; k <= K; k++) {
		cout << "Rout[" << k << "]";
		cout << "0-> " << y[k] << "->";
		int s = y[k];
		while (s > 0) {
			cout << s << "->";
			s = x[s];
		}
		cout << "0" << endl;
	}
}
bool check(int v, int k) {
	if (visited[v]) {
		return false;
	}
	if (load[k] + d[v] > Q) {
		return false;
	}
}

void TryY(int k) {
	for (int v = y[k - 1]; v <= n; v++) {
		if (check(v, k)) {
			y[k] = v;
			visited[v] = true;
			load[k] = load[k] + d[v];
			segments += 1;
			if (k == K) {
				TryX(y[1], 1);
			}
			else {
				TryY(k + 1);
			}

			segments -= 1;
			visited[v] = false;
			load[k] -= d[v];
		}
	}
}


bool checkX(int v, int k) {
	if (visited[v] == true) {
		return false;
	}
	if (load[k] + d[v] > Q) {
		return false;
	}
	if (v == 0) {
		return true;
	}
}
void TryX(int s, int k) {
	// twhr giá trị cho điểm tiêp theo của điểm s
	for (int v = 1; v <= n; v++) {
		if (checkX(v, k)) {
			x[s] = v; // x[v] next
			visited[v] = true;
			load[k] += d[v];
			segments += 1;
			if (v == 0) {
				if (k == K) {
					if (segments = (n + K)) {
						solution();
					}
				}
				else {
					TryX(y[k + 1], k + 1);
				}
			}
			else {
				TryX(v, k);
			}

			visited[v] = false;
			load[k] -= d[v];
			segments -= 1;
		}
	}
}
void input() {
	cin >> n >> K >> Q;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
		
}

void solve() {
	y[0] = 0;
	d[0] = 0;
	for (int k = 1; k <= K; k++) {

	}
	for (int v = 1; v <= n; v++) {
		visited[v] = false;
	}
}
int main() {
	y[0] = 0;
	return 0;
}