#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, w, n;
    
    vector<int> depth(31, 0), quantity(31, 0);
    
    bool fst = true;
    
    while(cin>>t>>w){
        if(fst) fst = false;
        else cout<<endl;
        
        cin>>n;
        
        for(int i = 1; i <= n; i++) cin>>depth[i]>>quantity[i], depth[i] *= 3*w;
        
        vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
        
        for(int i = 1; i <= n; i++) for(int j = t; j > 0; j--)
            if(depth[i] <= j) dp[i][j] = max(dp[i-1][j], quantity[i] + dp[i-1][j - depth[i]]);
            else dp[i][j] = dp[i-1][j];
            
        cout<<dp[n][t]<<endl;
        
        vector<int> picked;
        
        for(int i = n; i > 0; --i) if(dp[i][t] != dp[i-1][t]){
            picked.push_back(i);
            t -= depth[i];
        }
        
        cout<<picked.size()<<endl;
        
        for(int i = picked.size() - 1; i >= 0; i--) cout<<depth[picked[i]]/w/3<<" "<<quantity[picked[i]]<<endl;
    }
}
