#include <bits/stdc++.h>

using namespace std;

int a[1000], n;
int mem[1000];
//# mảng ghi nhớ lời giải các bài toán con đã được giải

void init()
{
    memset(mem, -1, sizeof(mem));
}

//# Quy hoạch động,
//# Hàm lis(i) trả về độ dài dãy con tăng dài nhất kết thúc bởi a[i]
int lis(int i)
{
    if (i == 1)
    {
        mem[0] = 1;
    }
    int tmp = 0;
    for (int j = i-1; j >= 0; j--)
    {
        if (a[j] < a[i] && mem[j] > tmp)
        {
            tmp = mem[j];
        }
        mem[i] = tmp + 1;
    }
    return mem[i];
}
//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
        trace(j);
        break;
        }
    }
    cout << a[i] << " ";
}
int main(){
    //cout << "ho ten: Tang The Toan" << endl;
    //cout << "MSSV: 20183998" << endl;
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
        res = lis(i);
        pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    cout << endl;
    return 0;
}
