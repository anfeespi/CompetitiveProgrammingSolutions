#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, o, d, cases = 1;
    while(cin>>n && n != 0){
        map<int, vector<int>> graph;
        while(n--){
            cin>>o>>d;
            graph[o].push_back(d);
            graph[d].push_back(o);
        }
        
        int s, ttl;
        
        //BFS pero con map :D
        while(cin>>s>>ttl && s != 0 && ttl != 0){
            queue<int> q;
            map<int, int> dist;
            
            int rn = 1;
            
            dist[s] = 0;
            q.push(s);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                
                for(int i = 0; i < graph[u].size(); i++){
                    int v = graph[u][i];
                    if(!dist.count(v)){
                        dist[v] = dist[u] + 1;
                        if(dist[v] <= ttl){
                            q.push(v);
                            rn++;
                        }
                    }
                }
            }
            
            cout<<"Case "<<cases++<<": "<<graph.size() - rn<<" nodes not reachable from node "<<s<<" with TTL = "<<ttl<<"."<<endl;
        }
    }
}
