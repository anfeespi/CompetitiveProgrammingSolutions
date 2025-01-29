#include <bits/stdc++.h>

using namespace std;

int dijkstra(int N, vector<vector<pair<int,int>>>& graph) {
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto p : graph[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, cases = 1;
    cin>>t;
    
   while(t--){
        int n, m;
        cin>>n>>m;
        
        vector<vector<pair<int,int>>> graph(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin>>u>>v>>w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        int result = dijkstra(n, graph);
        
        cout<<"Case "<<cases++<<": "<<(result == INT_MAX ? "Impossible" : to_string(result))<<endl;
    }
}
