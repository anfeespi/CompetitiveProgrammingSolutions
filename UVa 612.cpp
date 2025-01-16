#include <bits/stdc++.h>

using namespace std;

class dna{
    public:
        string str;
        
        int calculateNum(){
            int aux, sum = 0;
            for(int i = 0; i < str.length(); i++){
                if(i != 0 && str[i] == str[i-1]){
                    sum += aux;
                }else{
                    aux = 0;
                    for(int j = i; j < str.length(); j++){
                        if(i != j; str[i] > str[j]) aux++;
                    }
                    sum += aux;
                }
            }
            return sum;
        }
};

bool comp(dna a, dna b){
    return a.calculateNum() < b.calculateNum();
}


int t, n, m;
vector<dna> dnas;
string s;
int main(){
    cin>>t;
    while(t--){
        dnas.clear();
        cin>>n>>m;
        while(m--){
            cin>>s;
            dna auxd;
            auxd.str = s;
            dnas.push_back(auxd);
        }
        
        stable_sort(dnas.begin(), dnas.end(), comp);
        
        for(auto x : dnas)
            cout<<x.str<<endl;
            
        if(t)
            cout<<endl;
    }
}
