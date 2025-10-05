#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n;
    double size, animals, degree, total;
    
    cin>>t;
    
    while(t--){
        cin>>n;
        total = 0;
        while(n--){
            cin>>size>>animals>>degree;
            total += (size / animals) * degree * animals;
        }
        
        cout<<total<<endl;
    }
}
