#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;


ll t, n, factorial[21];
string s;

void calculateFactorial(){
    factorial[0] = 1;
    for(int i = 1; i < 21; i++)
        factorial[i] = i * factorial[i-1];
}

void printPermutation(string s, ll p){
    for(int i = 0; i < s.size(); i++){
        sort(s.begin()+i, s.end());
        
        if(p == 0)
            break;
            
        int pos = i + p / factorial[s.size() - i - 1];
        swap(s[i], s[pos]);
        p %= factorial[s.size() - i - 1];
    }
    
    cout<<s<<endl;
}

int main(){
    calculateFactorial();
    
    cin>>t;
    while(t--){
        while(cin>>s>>n){
            printPermutation(s, n);
        }
    }
}
