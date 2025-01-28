#include <bits/stdc++.h>

using namespace std;

int dfs(int node, vector<vector<int>> &graph, vector<vector<bool>> &visitedEdges, int currentLength) {
    int maxLength = currentLength;
    for (int neighbor : graph[node]) {
        if (!visitedEdges[node][neighbor]) {
            visitedEdges[node][neighbor] = true;
            visitedEdges[neighbor][node] = true;
            maxLength = max(maxLength, dfs(neighbor, graph, visitedEdges, currentLength + 1));
            visitedEdges[node][neighbor] = false;
            visitedEdges[neighbor][node] = false;
        }
    }
    return maxLength;
}

int main() {
    int n, m, o, d;
    while(cin>>n>>m && n != 0 && m != 0){
        vector<vector<int>> graph(n);
        graph.resize(n);
        
        while(m--){
            cin>>o>>d;
            graph[o].push_back(d);
            graph[d].push_back(o);
        }
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        int ll = 0;
        for(int i = 0; i < n; i++){
            ll = max(ll, dfs(i, graph, visited, 0));
        }
        
        cout<<ll<<endl;
    }
}
