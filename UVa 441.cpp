#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> s(14);
bool pr = true;

int main(){
    while(cin>>N && N != 0){
        if(pr) pr = false;
        else cout<<endl;
        
        for(int i = 0; i < N; i++) cin>>s[i];
        
        
        for(int i = 0; i < N - 5; i++){
            for(int j = i+1; j < N - 4; j++){
                for(int k = j+1; k < N - 3; k++){
                    for(int l = k+1; l < N - 2; l++){
                        for(int m = l+1; m < N - 1; m++){
                            for(int n = m+1; n < N; n++){
                                cout<<s[i]<<" "<<s[j]<<" "<<s[k]<<" "<<s[l]<<" "<<s[m]<<" "<<s[n]<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
}
