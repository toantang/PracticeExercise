#include <iostream>
#include <bits/stdc++.h>
#define MAX 10000000

using namespace std;

unsigned long long n = 0;
unsigned long long a[MAX];
unsigned long long cnt_noti = 0;
vector<pair<unsigned long long, unsigned long long>> noti(MAX);

unsigned long long answer[MAX];

void inputRoad()
{
    cin >> n;
    for (unsigned long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void inputNoti()
{
    cin >> cnt_noti;
    for (unsigned long long i = 1; i <= cnt_noti; i++) {
        pair<unsigned long long, unsigned long long> v;
        cin >> v.first;
        cin >> v.second;
        noti.at(i) = v;
    }
}

void print_array()
{
    for (unsigned long long i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print_noti()
{
    for (unsigned long long i = 1; i <= cnt_noti; i++) {
        cout << "(" << noti.at(i).first << ", " << noti.at(i).second << ")" << endl;
    }

    cout << endl;
}

void getFirstAnswer()
{
    answer[0] = 1;
    for (int i = 1; i <= n-1; i++) {
        if (a[i] != a[i+1]) {
            answer[0] += 1;
        }
    }
}

void solution()
{
   for (int i = 1; i <= cnt_noti; i++) {
        unsigned long long k = noti.at(i).first;
        unsigned long long value = noti.at(i).second;
        int before = a[k-1];
        int mid = a[k];
        int last = a[k+1];

        if (k == 1) {
            if (mid == last) {
                if (value == last) {
                    answer[i] = answer[i-1] + 0;
                }
                else {
                    answer[i] = answer[i-1] + 1;
                }
            }
            else {
                if (value == last) {
                    answer[i] = answer[i-1] - 1;
                }
                else {
                    answer[i] = answer[i-1] + 0;
                }
            }
        }
        else if (k == n) {
            if (mid == before) {
                if (value == before) {
                    answer[i] = answer[i-1] + 0;
                }
                else {
                    answer[i] = answer[i-1] + 1;
                }
            }
            else {
                if (value == before) {
                    answer[i] = answer[i-1] - 1;
                }
                else {
                    answer[i] = answer[i-1] + 0;
                }
            }
        }
        else {
            a[k] = value;
            //print_array();
            //cout << a[k+1] << ", " << a[k] << ", " << a[k-1] << endl;

            if (before == last) {
                if (mid == before) {
                    if (value == before) {
                        answer[i] = answer[i-1] + 0;
                    }
                    else {
                        answer[i] = answer[i-1] + 2;
                    }
                }
                else {
                    if (value == before) {
                        answer[i] = answer[i-1] - 2;
                    }
                    else {
                        answer[i] = answer[i-1] + 0;
                    }
                }
            }
            else {
                if ((mid == before) || (mid == last)) {
                    if ((value == before) || (value == last)) {
                        answer[i] = answer[i-1] + 0;
                    }
                    else {
                        answer[i] = answer[i-1] + 1;
                    }
                }
                else {
                    if ((value == before) || (value == last)) {
                        answer[i] = answer[i-1] - 1;
                    }
                    else {
                        answer[i] = answer[i-1] + 0;
                    }
                }
            }
        }
        //cout << "anwser[" << i << "] = " << answer[i] << endl;
        cout << answer[i] << endl;
        //cout << endl;
    }
}
int main()
{
    inputRoad();
    inputNoti();
    getFirstAnswer();
    solution();
    //print_noti();

    //cout << "answer first = " << answer[0] << endl;
    //cout << endl;

    return 0;
}
