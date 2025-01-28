#include <bits/stdc++.h>

using namespace std;

vector<int> memo(101);

void calculate(){
    memo[1] = 1;
    for(int i = 1; i <= 100; i++){
        memo[i] = i*i + memo[i-1];
    }
}

int main(){
    calculate();
    int n;
    while(cin>>n && n != 0){
        cout<<memo[n]<<endl;
    }
}
