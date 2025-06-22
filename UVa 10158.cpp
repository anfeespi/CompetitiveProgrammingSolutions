#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) \
    for(int i = int(a); i <= int(b); i++)
    
vector<int> pset, enemy;

void initSet(int _size){
    pset.resize(_size);
    REP(i, 0, _size-1)
        pset[i] = i;
        
    enemy.resize(_size, -1);
}

int findSet(int i){
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}

void unionSet(int i, int j){
    int x = findSet(i);
    int y = findSet(j);
    
    if(x != y)
        pset[x] = y;
}

int setFriends(int i, int j){
    int pi = findSet(i), pj = findSet(j);
    int ei = enemy[pi], ej = enemy[pj];
    
    if(pi == ej || pj == ei) return -1;
    
    unionSet(pi, pj);
    int f = findSet(pi);
    
    if(ei != -1 && ej != -1){
        unionSet(ei, ej);
        enemy[f] = findSet(ei);
        enemy[enemy[f]] = f;
    } else if (ei != -1){
        enemy[f] = ei;
        enemy[ei] = f;
    } else if (ej != -1){
        enemy[f] = ej;
        enemy[ej] = f;
    }
    
    return 0;
}

int setEnemies(int i, int j){
    int pi = findSet(i), pj = findSet(j);
    if(pi == pj) return -1;
    
    int ei = enemy[pi], ej = enemy[pj];
    
    if(ei != -1) unionSet(ei, pj);
    else enemy[pi] = pj;
    
    if(ej != -1) unionSet(ej, pi);
    else enemy[pj] = pi;
    
    enemy[findSet(pi)] = findSet(pj);
    enemy[findSet(pj)] = findSet(pi);
    
    return 0;
}

int areFriends(int i, int j){
    return findSet(i) == findSet(j) ? 1 : 0;
}

int areEnemies(int i, int j){
    int pi = findSet(i), pj = findSet(j);
    int ei = enemy[pi];
    return(ei != -1 && findSet(ei) == pj) ? 1 : 0;
}

int main(){
    int n, c, x, y, aux;
    cin>>n;
    initSet(n);
    while(true){
        cin>>c>>x>>y;
        
        if(c == 0 && x == 0 && y == 0) break;
        if (c == 3)
            cout<<areFriends(x, y)<<endl;
        else if (c == 4)
            cout<<areEnemies(x, y)<<endl;
        else{
            aux = (c == 1) ? setFriends(x, y) : setEnemies(x, y);
            if(aux == -1) cout<<aux<<endl;
        }

    }
    
}
