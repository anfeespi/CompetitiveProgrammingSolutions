#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t, m, x, cases = 1;
    cin>>t;
    while(t--){
        cin>>m;
        n = 0;
        while(m--){
            cin>>x;
            n+= (x > 0 ? x : 0);
        }
        cout<<"Case "<<cases++<<": "<<n<<endl;
    }
}
