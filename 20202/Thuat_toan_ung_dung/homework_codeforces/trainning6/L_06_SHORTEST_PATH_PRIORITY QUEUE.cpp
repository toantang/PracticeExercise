#include <bits/stdc++.h>
#define MAX 1000006
using namespace std;

typedef struct canh {
    int v;
    int w;
}Edge;

int n;
int m;

void input() {

}

int find_shortest_path(int start, int des, vector<vector<Edge>> a) {
    vector<long long> d(n+1, 0);
    for (int i = 0; i <= n; i++) {
        d[i] = MAX;
    }
    d[start] = 0;
    priority_queue <pair<long long, int>> vertex_queue;
    vertex_queue.push({-0, start});
    while(!vertex_queue.empty()) {
        pair<long long, int> p = vertex_queue.top();
        vertex_queue.pop();
        long long distance = -p.first;
        int min_vertex = p.second;
        if (d[min_vertex] < distance) {
            continue;
        }
        for (Edge e : a[min_vertex]) {
            int v = e.v;
            int w = e.w;
            if (d[v] > d[min_vertex] + w) {
                d[v] = d[min_vertex] + w;
                vertex_queue.push({-d[v], v});
            }
        }
    }

    return d[des];
}
int main() {
    return 0;
}