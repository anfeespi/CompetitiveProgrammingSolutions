#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int cases = 1;
    while(cin>>s && s != "*"){
        cout<<"Case "<<cases++<<": "<<(s == "Hajj" ? "Hajj-e-Akbar" : "Hajj-e-Asghar")<<endl;
    }
}
