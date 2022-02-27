#include <iostream>

using namespace std;

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Merge(int a[], int L, int mid, int R)
{
    int nLeft = mid - L + 1;
    int nRight = R - mid;
    int left[nLeft], right[nRight];
    for (int i = 0; i < nLeft; i++)
    {
        left[i] = a[L+i];
    }
    for (int i = 0; i < nRight; i++)
    {
        right[i] = a[mid+i+1];
    }

    int i=0, j=0, k=L;
    while(i < nLeft && j < nRight)
    {
        if (left[i] < right[j]) {
            a[k] = left[i];
            i++;
        }
        else if (left[i] >= right[j]){
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < nLeft) {
        a[k] = left[i];
        k++;
        i++;
    }
    while(j < nRight) {
        a[k] = right[j];
        k++;
        j++;
    }
}

void merge_sort(int a[], int L, int R)
{

    if (L < R) {
        int mid = (R+L)/2;
        merge_sort(a, L, mid);
        merge_sort(a, mid+1, R);
        Merge(a, L, mid, R);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge_sort(a, 0, n-1);
    print_array(a, n);
    return 0;
}
