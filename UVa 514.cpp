#include <bits/stdc++.h>

using namespace std;

int n, current;

int main(){
    while(cin>>n && n != 0){
        while(true){
            bool repeat = true;
            stack<int> road;
            vector<int> train(n);
            
            for(int i = 0; i < n; i++){
                cin>>train[i];
                if(train[0] == 0){
                    repeat = false;
                    break;   
                }
            }
            
            if(!repeat) break;
            
            current = 1;
            bool possible = true;
            for(int i = 0; i < n; i++){
                while((road.empty() || road.top() != train[i]) && current <= n)
                    road.push(current++);
                
                if(!road.empty() && road.top() == train[i])
                    road.pop();
                
                else
                    possible = false;
            }
            
            if(possible) cout<<"Yes";
            else cout<<"No";
            cout<<endl;
        }
        cout<<endl;
    }
}
