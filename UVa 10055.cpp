#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long int i, j;
    
    while(cin>>i>>j){
        cout<<(i > j ? i - j : j - i)<<endl;
    }
}
