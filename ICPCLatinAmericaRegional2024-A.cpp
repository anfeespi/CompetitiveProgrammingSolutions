    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main(){
        string s;
        
        cin>>s;
        
        set<char> se;
        
        for(auto it : s) se.insert(it);
        
        cout<<s.length()-se.size();
    }
