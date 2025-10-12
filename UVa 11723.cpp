#include<bits/stdc++.h>

using namespace std;

int main(){
    double r, n;
    int casen = 1;
    
    while(cin>>r>>n && r != 0 && n != 0){
        double res = ceil(r/n) - 1;
        
        cout<<"Case "<<casen++<<": ";
        
        if(res > 26) cout<<"impossible";
        else cout<<res;
        
        cout<<endl;
    }
}
