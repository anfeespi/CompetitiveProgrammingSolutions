#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> palindromes; 

void createPalindromes(){
    string aux, rvs;
    for(int i = 0; i <= 23; i++){
        for(int j = 0; j <= 59; j++){
            
            if(i == 0) aux = to_string(j);
            else if(j <= 9) aux = to_string(i) + "0" + to_string(j);
            else aux = to_string(i)+to_string(j);
            
            rvs = aux;
            reverse(rvs.begin(), rvs.end());
            
            
            if(aux == rvs) palindromes.push_back(make_pair(i, j));
        }
    }
}

int main(){
    createPalindromes();
    
    int t, h, m;
    bool find;
    
    scanf("%d", &t);
    while(t--){
        scanf("%d:%d", &h, &m);
        find = false;
        for(int i = 0; i < palindromes.size(); i++){
            if(palindromes[i].first == h && palindromes[i].second > m){
                find = true;
                cout<<(palindromes[i].first <= 9 ? "0" : "")<<palindromes[i].first<<":"<<(palindromes[i].second <= 9 ? "0" : "")<<palindromes[i].second<<endl;
                break;
            }
            
            else if(palindromes[i].first > h){
                find = true;
                cout<<(palindromes[i].first <= 9 ? "0" : "")<<palindromes[i].first<<":"<<(palindromes[i].second <= 9 ? "0" : "")<<palindromes[i].second<<endl;
                break;
            }
        }
        
        if(find == false) cout<<"00:00"<<endl;
    }
}
