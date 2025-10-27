#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int k, total = 0, count = 1, posi1 = 0, posi2 = 0;
    string s, p1 = "", p2 = "";
    
    cin>>k>>s;
    
    //1 = 01010101
    //2 = 10101010
    if(k == 2){
        for(int i = 0; i < s.length(); i++){
            if(i % 2 == 0){
                p1 += "0";
                p2 += "1";
                if(s[i] == '0') posi2++;
                else posi1++;
            }else{
                p1 += "1";
                p2 += "0";
                if(s[i] == '0') posi1++;
                else posi2++;
            }
            
        }
        
        if(posi1 < posi2){
            s = p1;
            total = posi1;
        }else{
            s = p2;
            total = posi2;
        }
        
    }else{
        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i-1]){
                count++;
                
                if(count == k){
                    count = 1;
                    
                    if(i < s.length() - 1 && s[i] != s[i+1]){
                        s[i-1] = s[i-1] == '1' ? '0' : '1';
                    }else{
                        s[i] = s[i] == '1' ? '0' : '1';
                    }
                    total++;
                }
            }else{
                count = 1;
            }
        }
    }
    
    
    cout<<total<<" "<<s<<endl;
}
