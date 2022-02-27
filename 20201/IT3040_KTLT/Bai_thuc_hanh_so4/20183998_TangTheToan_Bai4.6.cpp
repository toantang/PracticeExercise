#include<bits/stdc++.h>

using namespace std;

void bfs(vector< list<int> > adj) {
    list<int> S;
    vector<bool> visited(adj.size());
    S.push_back(1);
    while (!S.empty())
    {
        int s;
        s = S.front();
        cout<< s << endl;
        S.pop_front();

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i]){
                visited[*i] = true;
                S.push_back(*i);
            }
    }
}

int main()
{
    int n = 7;
    cout << "ho ten: Tang The Toan" << endl;
    cout << "MSSV: 20183998" << endl;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    bfs(adj);
}
