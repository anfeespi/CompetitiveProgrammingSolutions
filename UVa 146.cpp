#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    while(cin>>s && s != "#"){
        if(next_permutation(s.begin(), s.end()))
            cout<<s;
        else
            cout<<"No Successor";
        cout<<endl;
    }    
}
