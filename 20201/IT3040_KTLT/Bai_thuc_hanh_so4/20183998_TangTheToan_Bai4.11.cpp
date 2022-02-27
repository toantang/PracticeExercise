#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#define MAX 1e9
using namespace std;

int n, s;
int avai;
int res;
int MIN;
vector< pair<int, int> > a_k;

void scan(){
	int a, k;
	pair<int, int> temp;
	int m = n;
	while(m--){
		cin >> a >> k;
		temp.first = a;
		temp.second = k;
		a_k.push_back(temp);
	}
}

void process(int w){
	for(int i = 0; i <= avai; i++){
		int temp = (a_k[w].first - i*a_k[w].second) > 0 ? (a_k[w].first - i*a_k[w].second) : 0;
		if((res+temp) < MIN){
			res+=temp;
			avai-=i;
			if(w == n){
				MIN = res;
			}
			else
				if(w < n){
					process(w+1);
				}
			res-=temp;
			avai+=i;
		}
	}
}



int main(){
	cin >> n >> s;
	avai = s;
	pair<int, int> temp;
	a_k.push_back(temp);
	scan();
	MIN = MAX;
	process(1);
	cout << MIN << endl;
}
