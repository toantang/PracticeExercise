#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

unsigned long long getMaxArea(unsigned long long a[], unsigned long long n)
{

    stack<unsigned long long> s;

    unsigned long long max_area = 0;
    unsigned long long tp;
    unsigned long long area_with_top;
    unsigned long long i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top
        // stack, push it to stack
        if (s.empty() || a[s.top()] <= a[i])
            {
                s.push(i++);
            }
        else
        {
            tp = s.top();
            s.pop();
            if (s.empty()) {
                area_with_top = a[tp] * i;
            }
            else {
                area_with_top = a[tp] * (i - s.top() - 1);
            }

            if (max_area < area_with_top)
            {
                max_area = area_with_top;
            }
        }
    }

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        if (s.empty())
        {
            area_with_top = a[tp] * i;
        }
        else {
            area_with_top = a[tp] * (i - s.top() - 1);
        }

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    //cout << max_area << endl;
    return max_area;
}

int main()
{
    unsigned long long n;
    while(true)
    {
        cin >> n;
        if (n == 0) {
            break;
        }
        unsigned long long a[MAX];
        for(unsigned long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << getMaxArea(a, n) << endl;
    }
    return 0;
}
