#include <bits/stdc++.h>

using namespace std;

int value(char c)
{
	if (c != ' ' && (c > 'z' || c < 'a'))
	{
		return 0;
	}
	if (c == ' ')
	{
		return 1;
	}
	if (c >= 'w')
	{
		return c - 'w' + 1;
	}
	if (c >= 't')
	{
		return c - 't' + 1;
	}
	if (c >= 'p')
	{
		return c - 'p' + 1;
	}
	if (c >= 'm')
	{
		return c - 'm' + 1;
	}
	if (c >= 'j')
	{
		return c - 'j' + 1;
	}
	if (c >= 'g')
	{
		return c - 'g' + 1;
	}
	if (c >= 'd')
	{
		return c - 'd' + 1;
	}
	return c - 'a' + 1;
}

int main()
{
	int n;
	cin >> n;
	vector<string> arr(n);
	cin.ignore();
	for (int i = 0; i < n; ++i)
	{
		getline(cin, arr[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		int res = 0;
		for (char c : arr[i])
		{
			res += value(c);
		}
		cout << "Case #" << i + 1 << ": " << res << endl;
	}

	return 0;
}
