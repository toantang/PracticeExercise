#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    printf("ho ten: Tang The Toan\n");
    printf("MSSV: 20183998\n");
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    sort(a.begin(), a.end(), [] (vector<int> v1, vector<int> v2)-> bool {
        int s1 = 0, s2 = 0;
        int size1 = v1.size();
        int size2 = v2.size();
        for(int i = 0; i < size1; i++) {
            s1 = s1 + v1[i];
        }

        for(int i = 0; i < size2; i++) {
            s2 = s2 + v2[i];
        }

        return s1 > s2;
    });

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
