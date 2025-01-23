#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l;
    while(true){
        cin>>l;
        if(l==0) break;
        
        vector<int> dpos;
        vector<int> rpos;
        
        string s;
        cin>>s;
        
        int d=l;
        
        if(s.find("Z") != std::string::npos){
            d = 0;
        }else{
            for(int i=0; i<l; i++){
                if(s[i]=='R'){
                    dpos.push_back(i);
                }else if(s[i]=='D'){
                    rpos.push_back(i);
                }
            }
            for(int i=0; i<dpos.size(); i++){
                bool romp = false;
                for(int j=0; j<rpos.size(); j++){
                    if(dpos[i]-rpos[j] == 0){
                        d = 0;
                        romp = true;
                        break;
                    }
                    else if(abs(dpos[i]-rpos[j]) < d) d = abs(dpos[i]-rpos[j]);
                }
                if(romp) break;
            }
        }
        
        
        cout<<d<<endl;
    }
}
