#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<vector<int>> adj;
vector<int> dp, endNode;

int dfs(int u) {
    if(dp[u] != -1) return dp[u];
    int bst = 0;
    int bstD = u;
    for (int v : adj[u]) {
        int cl = 1 + dfs(v);
        int cD = endNode[v];
        if (cl > bst || (cl == bst && cD < bstD)) {
            bst = cl;
            bstD = cD;
        }
    }
    dp[u] = bst;
    endNode[u] = bstD;
    return dp[u];
}

vector<int> voi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int casen = 1;
    while (cin>>n && n) {
        cin>>s;
        adj.resize(n + 1);
        fill(adj.begin(), adj.end(), voi);
        
        int p, q;
        while (cin>>p>>q && p || q) {
            adj[p].push_back(q);
        }
        dp.resize(n + 1);
        fill(dp.begin(), dp.end(), -1);
        
        endNode.resize(n + 1);
        for(int i = 1; i <= n; i++) endNode[i] = i;

        int longest = dfs(s);
        int dest = endNode[s];

        cout<<"Case "<<casen++<<": The longest path from "<<s<<" has length "<<longest<<", finishing at "<<dest<<"."<<endl<<endl;
    }
}
