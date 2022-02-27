#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <map>
#define MAX 1e9

using namespace std;

vector<int> dijkstra(const vector< vector< pair<int, int> > > &adj) {
	int size = adj.size();
	vector<int> cost(size);
	for(int i = 0; i < size; i++){
		cost[i] = MAX;
	}
	//
	vector<bool> passed(size);
	map<int, int> Q;
	cost[0] = 0;
	Q.insert({0, cost.at(0)});

	while(!Q.empty()){
		int pos;
		int min_cost = MAX;
		for(const auto &e : Q){
			if(!passed[e.first])
				if(e.second < min_cost){
					pos = e.first;
					min_cost = e.second;
				}
		}
		for(int i = 0; (unsigned) i < adj[pos].size(); i++){
			int point = adj[pos][i].first;
			int p_p = adj[pos][i].second;
			if(!passed[point]){
				cost.at(point) = min(cost.at(pos) + p_p, cost.at(point));
				Q[point] = cost.at(point);
			}
		}
		passed[pos] = true;
		Q.erase(pos);
	}
	return cost;
}

int main() {
	cout << "ho ten: Tang The Toan" << endl;
    cout << "MSSV: 20183998" << endl;
	int n = 9;
	vector< vector< pair<int, int> > > adj(n);
	auto add_edge = [&adj] (int u, int v, int w) {
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
 	};

	add_edge(0, 1, 4);
	add_edge(0, 7, 8);
	add_edge(1, 7, 11);
	add_edge(1, 2, 8);
	add_edge(2, 3, 7);
	add_edge(2, 8, 2);
	add_edge(3, 4, 9);
	add_edge(3, 5, 14);
	add_edge(4, 5, 10);
	add_edge(5, 6, 2);
	add_edge(6, 7, 1);
	add_edge(6, 8, 6);
	add_edge(7, 8, 7);

	vector<int> distance = dijkstra(adj);
	for (int i = 0; i < distance.size(); ++i) {
		cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
	}

	return 0;
}
