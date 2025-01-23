#include<bits/stdc++.h>

using namespace std;

char uebfa[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(){
    char c;

    while(scanf("%c", &c) != EOF){
        c = toupper(c);
        if(!isspace(c)){
            for(int i = 0; uebfa[i]; i++){
                if(c == uebfa[i]){
                    cout<<uebfa[i-1];
                    break;
                }
            }
        }else
            cout<<c;
    }

}
