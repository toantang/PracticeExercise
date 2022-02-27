#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void printSet(set<int> s) {
	for (auto i : s) {
		cout << i << " ";
	}
	cout << endl;
}
int main() {
	set<int> S1;
	set<int> S2;
	for (int i = 1; i <= 10; i++) {
		int r = 4 + rand() % (15 + 1 - 4);
		int r2 = 4 + rand() % (15 + 1 - 4);
		S1.insert(r);
		S2.insert(r2);
	}

	cout << "S1 = ";
	printSet(S1);

	cout << "S2 = ";
	printSet(S2);

	set<int> S;
	set_intersection(S1.begin(), S1.end(), S2.begin(), S2.end(), inserter(S, S.begin()));
	printSet(S);

	set<int> s;
	set_union(S1.begin(), S1.end(), S2.begin(), S2.end(), inserter(s, s.begin()));
	printSet(s);

	set<int> s1;
	// cac phan tu xuat hien ở S1 nhưng ko có ở S2
	set_difference(S1.begin(), S1.end(), S2.begin(), S2.end(), inserter(s1, s1.begin()));
	printSet(s1);
	return 0;
}