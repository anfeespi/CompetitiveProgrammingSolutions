#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) \
    for (int i = int(a); i <= int(b); i++)
    
vector<int> pset(1000);

void initSet(int _size) { 
    pset.resize(_size); REP (i, 0, _size - 1) pset[i] = i; 
}

int findSet(int i) { 
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); 
}

void unionSet(int i, int j) {
    pset[findSet(i)] = findSet(j);
}

bool isSameSet(int i, int j) { 
    return findSet(i) == findSet(j); 
}

int numberOfSets(){
    bitset<26> visited;
    
    for(int i = 0; i < pset.size(); i++){
        visited[findSet(i)] = true;
    }
    
    return visited.count();
}

int main(){
    int t, n, s, u, i, j;
    char aux;
    string st;
    
    cin>>t;
    
    while(t--){
        s = u = 0;
        cin>>n;
        cin.ignore();
        initSet(n);
        
        while(getline(cin, st)){
            if(st == "") break;
            
            stringstream ss(st);
            
            ss>>aux>>i>>j;
            
            i--, j--;
            
            if(aux == 'c') unionSet(i, j);
            
            else if(aux == 'q'){
                if(isSameSet(i, j)) s++;
                else u++;
            }
        }
        
        cout<<s<<","<<u<<endl;
        
        if(t) cout<<endl;
    }
    
    
}
