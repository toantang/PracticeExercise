// C++ implementation of the
// above approach
//#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

int countSubstring(string& S, int& n)
{
	int ans = 0;
	int i = 0;
	while (i < n) {
		int cnt0 = 0, cnt1 = 0;
		if (S[i] == '0') {

			while (i < n && S[i] == '0') {
				cnt0++;
				i++;
			}
			int j = i;
			while (j < n && S[j] == '1') {
				cnt1++;
				j++;
			}
		}

		else {
			while (i < n && S[i] == '1') {
				cnt1++;
				i++;
			}
			int j = i;
			while (j < n && S[j] == '0') {
				cnt0++;
				j++;
			}
		}
		ans += min(cnt0, cnt1);
	}

	// Return answer
	return ans;
}

int main()
{
	//string S = "1001011";
	string S;
	cin >> S;
	int n = S.length();

	cout << 2*countSubstring(S, n);
	return 0;
}
