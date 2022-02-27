#include <iostream>
#define MAX 100

using namespace std;

int memory[MAX];

int F(int n) {
	if (n <= 1) {
		memory[1] = 1;
		return 1;
	}
	if (memory[n] > 0) {
		return memory[n];
	}

	memory[n] = F(n - 1) + F(n - 2);
	return memory[n];
}
int main() {
	for (int i = 0; i < MAX; i++) {
		memory[i] = 0;
	}
	memory[0] = 1;
	memory[1] = 1;
	for (int n = 2; n <= 10; n++) {
		cout << F(n) << endl;
	}
	return 0;
}