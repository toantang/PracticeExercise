#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

bool checkEven(int x){
    if (x % 2 == 0) {
        return true;
    }
    return false;
}
void delete_even(vector<int> &a) {
    a.erase(remove_if(a.begin(), a.end(), checkEven), a.end());
}

void sort_decrease(vector<int> &a) {
    sort(a.rbegin(), a.rend());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> v(a.size() + b.size());
    merge(a.rbegin(), a.rend(), b.rbegin(), b.rend(), v.rbegin());
    return v;
}

int main() {
    cout << "ho ten: Tang The Toan" << endl;
    cout << "MSSV: 20183998" << endl;
    int m, n, u;
    std::vector<int> a, b;

    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    //std::vector<int> v(a.size() + b.size());
    //merge_vectors(a, b, v);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
