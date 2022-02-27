#include<stdio.h>
#include<complex.h>
#include<iostream>
#include<vector>

using namespace std;

using cd = complex<double> ;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

vector<int> input(int n){
	vector<int> a(n+1);
	int temp;
	for(int i=0;i<=n;i++){
		do{
			temp = scanf("%d",&a[i]);
		}while(std::abs(a[i]) > 100);
	}
	return a;
}

void print(vector<int> a){
	for(int e : a)
		cout << e << " ";
}


int main(){
	int n,m;
	cin >> n;
	vector<int> a = input(n);
	cin >> m;
	vector<int> b = input(m);
	a = multiply(a,b);
	int res = 0;
	for(int e : a)
		res = res xor e;
	cout << res;
	
}
