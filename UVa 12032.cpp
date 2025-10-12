#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, n, l, c, casen = 1, k;
    bool rep;
    cin>>t;
    while(t--){
        k = -1;
        rep = false;
        
        cin>>n;
        l = 0;
        while(n--){
            cin>>c;
            
            if(k == c - l) rep = true;
            else k = max(k, c - l);
            
            l = c;
        }
        
        cout<<"Case "<<casen++<<": "<<(rep ? k + 1 : k)<<endl;
    }
}
