#include <bits/stdc++.h>

using namespace std;

int f91(int N){
    if(N >= 101) return N - 10;
    
    return 91;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    while(cin>>n && n!= 0) cout<<"f91("<<n<<") = "<<f91(n)<<endl;
}
