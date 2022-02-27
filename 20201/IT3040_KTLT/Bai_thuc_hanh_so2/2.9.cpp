#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}


// khai báo các biến phụ trợ cần thiết
const int N = 1000000000;
double y[N+5];
const double DELTA = 2.0*LIMIT/N;

// hàm chuẩn bị dữ liệu
void precalc() {
    for (int i=0; i<= N + 4; i++) {
        y[i] = sigmoid_slow(- LIMIT + DELTA * i);
    }
}

// hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x) {
    // Nếu x quá bé
    if (x <= - LIMIT) {
        return 0;
    }

    // Nếu x quá lớn
    if (x >= LIMIT) {
        return 1;
    }

    // Lấy 2 giá trị gần nhất
    int i = (x + LIMIT) / DELTA;
    // Lấy TBC của 2 giá trị
    return (x - (- LIMIT + DELTA * i)) / DELTA * (y[i+1] - y[i]) + y[i];

}


double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;

    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
    return taken;
}

bool is_correct(const std::vector<double> &a, const std::vector<double> &b) {
    const double EPS = 1e-6;

    if (a.size() != b.size()) return false;
    for (int i = 0; i<(int)a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}

int main() {
    prepare_input();
    precalc();

    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));

    if (is_correct(a, b) && (slow/fast > 1.5)) {
        cout << "Correct answer! Your code is faster at least 30%!\n";
    } else {
        printf("Wrong answer or your code is not fast enough!\n");
    }

    return 0;
}
