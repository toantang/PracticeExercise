#include <bits/stdc++.h>

using namespace std;

int UCLN(int a, int b)
{
    if (b == 0) {
        return a;
    }
    else {
        return UCLN(b, a%b);
    }
}
int pour(int fromBottle, int toBottle, int c)
{
    int from = fromBottle;
    int to = 0;
    int step = 1;
    while(from != c && to != c) {
        int temp = min(from, toBottle - to);
        to   += temp;
        from -= temp;
        step++;

        if (from == c || to == c) {
            break;
        }
        if (from == 0) {
            from = fromBottle;
            step++;
        }
        if (to == toBottle) {
            to = 0;
            step++;
        }
    }
    return step;
}

int solution(int bottle1, int bottle2, int c)
{
    if (bottle1 > bottle2) {
        swap(bottle1, bottle2);
    }
    int ucln = UCLN(bottle2, bottle1);
    if (c > bottle2) {
        return -1;
    }
    if ((c%ucln) != 0) {
        return -1;
    }
    return min(pour(bottle1, bottle2, c), pour(bottle2, bottle1, c));
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solution(a, b, c);
    return 0;
}
