#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> v;
    for (auto &aa: a) {
        v.insert(aa);
    }

    for (auto &bb: b) {
        for (auto &vv : v) {
                if (bb.first == vv.first) {
                if (bb.second > vv.second) {
                    v.erase(vv.first);
                    v.insert(bb);
                }
            }
            else {
                v.insert(bb);
            }
        }
    }
    return v;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> v;
    for (auto &aa: a) {
        for (auto &bb: b) {
            if (aa.first == bb.first) {
                pair<T, double> c;
                c.first = aa.first;
                if(aa.second < bb.second) {
                    c.second = aa.second;
                }
                else {
                    c.second = bb.second;
                }
                v.insert(c);
            }
        }
    }
    return v;
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    cout << "ho ten: Tang The Toan" << endl;
    cout << "MSSV: 20183998" << endl;
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}
