#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;

    while(cin>>n>>k){
        cout<<n + (n - 1) / (k - 1)<<endl;
    }
}
