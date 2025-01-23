#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,m;
    while(cin>>n>>m){
        if(n==0 && m==0) break;
        
        int cabezas[20001],caballeros[20001];
        for(int i=0; i<n; i++) cin>>cabezas[i];
        for(int i=0; i<m; i++) cin>>caballeros[i];
        
        sort(cabezas,cabezas + n);
        sort(caballeros,caballeros + m);
        
        bool doomed;
        
        int pos = 0;
        long long res = 0;
        
        for(int i=0; i<n; i++){
            doomed = false;
            for(int j = pos; j<m ; j++){
                if(cabezas[i] <= caballeros[j]){
                    res += caballeros[j];
                    pos = j+1;
                    doomed = true;
                    break;
                }
            }
            if(doomed == false) break;
        }
        if(doomed) cout<<res<<endl;
        else cout<<"Loowater is doomed!"<<endl;
    }
}
