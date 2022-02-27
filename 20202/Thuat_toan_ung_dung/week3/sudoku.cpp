#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool row[9][10]; //col[r][v] = true nghia la v da xuat hien tren hang r
bool col[9][10];
bool ms[3][3][10] // ms[i][j] = true nghia la v da xuat hien trong bang con i, j
int x[9][9];

int n;// so hang so cot
bool check(int v, int r, int c)
{
    if (row[r][v] != 1 && col[c][v] != 1 && ms[r/3][c/3][v] != 1)
    {
        return true;
    }
    else {
        return false;
    }
}
void TRY(int r, int c)
{
    for (int v = 1; v <= n; v++) {
        if (check(int v, int r, int c)) {
            row[r][v] = 1;
            col[c][v] = 1;
            ms[r/3][c/3][v] = 1;
            if (r == n-1 && c == n-1) {
                solution();
            }
            else {
                if (r == n-1) {
                    TRY(r, c+1);
                }
                else {
                    TRY(r+1, c);
                }
            }
            row[r][v] = 0;
            col[r][v] = 0;
            ms[r/3][c/3][v] = 0;
        }
    }
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        col[i] = -1;
        row[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++)
        {
            ms
        }
    }
    return 0;
}
