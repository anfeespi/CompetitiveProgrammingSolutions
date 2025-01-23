#include <bits/stdc++.h>

using namespace std;

string s, aux;
int i;
int main(){
    while(getline(cin, s)){
        for(i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                aux = s[i] + aux;
            }else{
                cout<<aux<<" ";
                aux = "";
            }
        }
        
        cout<<aux<<endl;
        aux = "";
    }    
}
