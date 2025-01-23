#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[140];
    while(gets(s)!=NULL){
        
        int sum=0;
        for(int i=0; i<strlen(s); i++){
            
            if(s[i]>='0' && s[i]<='9'){
                sum+=s[i]-'0';
            }
            else {
                if(s[i]=='!'){
                    cout<<"\n";
                }
                for(int j=sum; j>0; j--){
                    if(s[i]=='b') cout<<" ";
                    else cout<<s[i];
                }
                sum=0;
            }
        }
        cout<<"\n";
        
    }
    return 0;
}
