#include <bits/stdc++.h>

using namespace std;

int size;

int resp(int &k){
    int pos, prev;
    pos = 1;
    while(pos < size){
        if(k%2 != 0){
            k = k/2 + 1;
            prev = pos;
            pos = 2 * pos;
        }else if(k%2 == 0){
            k /= 2;
            prev = pos;
            pos = (2 * pos) + 1;
        }
    }
    
    return prev;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int l, d, i, endd;
    
    cin>>l;
    
    while(l--){
        cin>>d>>i;
        
        size = pow(2, d);
        
        cout<<resp(i)<<endl;
    }
    
    cin>>endd;
}
