#include <bits/stdc++.h>

using namespace std;

int t, n, i;
vector<int> x;
vector<string> xp(1000000);
string s;
istringstream stream;

int main(){
    getline(cin, s);
    stream.str(s);
    stream>>t;
    
    stream.clear();
    
    while(t--){
        getline(cin, s);
        
        i = 0;
        x.clear();
        
        getline(cin, s);
        stream.str(s);
        while(stream >> n){
            x.push_back(n);
        }
        stream.clear();
        
        getline(cin, s);
        stream.str(s);
        while(stream >> s){
            xp[x[i]-1] = s;
            i++;
        }
        stream.clear();
        
        for(i = 0; i < x.size(); i++)
            cout<<xp[i]<<endl;
        if(t != 0)
            cout<<endl;
    }

}
