#include <bits/stdc++.h>

using namespace std;

map<char, int> lets = {
    {'M', 1},
    {'A', 3},
    {'R', 2},
    {'G', 1},
    {'I', 1},
    {'T', 1}
};

int main(){
    int n;
    string line;
    cin>>n;
    cin.ignore();
    while(n--){
        int pzs = INT_MAX;
        
        getline(cin, line);
        map<char, int> cont;
        
        for(char l : line){
            cont[l]++;
        }
        
        for(auto it : lets){
            char l = it.first;
            int q = it.second;
            
            if(cont.find(l) != cont.end()){
                pzs = min(pzs, cont[l] / q);
            }else{
                pzs = 0;
                break;
            }
        }
        
        cout<<pzs<<endl;
    }
}
