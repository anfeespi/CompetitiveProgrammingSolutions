#include <bits/stdc++.h>

using namespace std;

int main(){
    int c;
    string s;
    
    while(getline(cin, s)){
        c = 0;
        bool w = false;
        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])){
                if(!w) c++, w = true;
            }
            else w = false;
        }
        
        cout<<c<<endl;
    }
}
