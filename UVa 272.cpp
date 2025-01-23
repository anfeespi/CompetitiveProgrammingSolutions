#include <bits/stdc++.h>

using namespace std;

string s;
int i;
bool open = true;

int main(){
    while(getline(cin, s)){
        for(i = 0; i < s.length(); i++){
            if(s[i] == '"'){
                if(open)
                    printf("``");
                else
                    printf("''");
                open = !open;
            }else{
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
}
