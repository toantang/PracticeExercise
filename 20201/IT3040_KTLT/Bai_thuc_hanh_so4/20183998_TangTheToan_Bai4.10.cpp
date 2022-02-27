#include <iostream>
#include <string>
#include <sstream>
//#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <utility>
using namespace std;

double IDF(vector< vector<string> > &docs, string &word){
	unsigned d = docs.size();
	int count = 0;
	for(vector<string> doc : docs){
		for(string _word : doc){
			if(_word == word){
				count++;
				break;
			}
		}
	}
	if(count == 0)
		return 0;
	return log(d/count) / log(2);
}

double TF(vector<string> &doc, string &word){
	int count = 0;
	for(string e : doc){
		if(e.compare(word)==0){
			count++;
		}
	}
	//
	priority_queue<int> Q;
	map<string, int> M;
	for(string e : doc){
		M[e] += 1;
	}
	for(pair<string, int> e : M){
		Q.push(e.second);
	}
	int max = Q.top();
	//
	return count/max;
}

vector<int> TF_IDF(vector< vector<string> > docs, vector< vector<string> > rules){
	vector<int> temp(rules.size());
	vector< map<int, double> > doc_score(rules.size());
	int i = 0;
	for(vector<string> rule : rules){
		int j = 1;
		for(vector<string> doc : docs){
			double score = 0;
			for(string word : rule){
				score += TF(doc, word)*IDF(docs, word);
			}
			doc_score[i][j] = score;
			j++;
		}
		i++;
	}
	i = 0;
	for(map<int, double> e : doc_score){
		double max = 0;
		int pos = 0;
		for(pair<int, double> p : e){
			if(p.second >= max){
				max = p.second;
				pos = p.first;
			}
		}
		temp[i] = pos;
		i++;
	}
	return temp;
}

vector< vector<string> > getDocs(int n){
	vector< vector<string> > temp;
	for(int i = 0; i < n; i++){
		vector<string> tokens;
		string s;
		cin >> s;
		stringstream ss(s);
		string token;
		while(getline(ss,token,',')){
			tokens.push_back(token);
		}
		temp.push_back(tokens);
	}
	return temp;
}

vector< vector<string> > getRules(int q){
	vector< vector<string> > temp;
	for(int i = 0; i < q; i++){
		vector<string> tokens;
		string s;
		cin >> s;
		stringstream ss(s);
		string token;
		while(getline(ss,token,',')){
			tokens.push_back(token);
		}
		temp.push_back(tokens);
	}
	return temp;
}

int main(){
	int n,q;
	cin >> n;
	vector< vector<string> > documents = getDocs(n);
	cin >> q;
	vector< vector<string> > rules = getRules(q);
	vector<int> result = TF_IDF(documents, rules);
	for(auto e : result){
		cout << e << endl;
	}
	return 0;
}
