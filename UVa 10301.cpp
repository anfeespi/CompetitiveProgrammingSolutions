#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) \
    for(int i = int(a); i <= int(b); i++)
    
vector<int> pset(1000);

void initSet(int _size){
    pset.resize(_size);
    REP(i, 0, _size-1)
        pset[i] = i;
}

int findSet(int i){
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}

void unionSet(int i, int j){
    pset[findSet(i)] = findSet(j);
}

bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
}

int numberOfSets(){
    bitset<1000> visited;
    
    for(int i = 0; i < pset.size(); i++){
        visited[findSet(i)] = 1;
    }
    
    return visited.count();
}

int sizeOfSet(int i){
    int rep = findSet(i);
    int count = 0;
    
    for(int j = 0; j < pset.size(); j++){
        if(findSet(j) == rep) count++;
    }
    
    return count;
}

int biggestSet(){
    vector<int> arr(pset.size(), 0);
    int larg = 0;
    
    
    for(int i = 0; i < pset.size(); i++){
        arr[findSet(i)]++;
        larg = max(larg, arr[findSet(i)]);
    }
    
    return larg;
}

class Circle{
    public:
        double x;
        double y;
        double radius;
};

vector<Circle> circles;

int main(){
    int n, j, sets;
    double d;
    
    while(cin>>n && n != -1){
        initSet(n);
        circles.clear();
        
        while(n--){
            Circle aux;
            cin>>aux.x>>aux.y>>aux.radius;
            circles.push_back(aux);
            
            if(circles.size() > 1){
                j = circles.size() - 1;
                for(int i = 0; i < j; i++){
                    if(!isSameSet(pset[i], pset[j])){
                        d = sqrt( pow(circles[i].x - circles[j].x , 2) + pow(circles[i].y - circles[j].y , 2) );
                        
                        if(circles[i].radius + circles[j].radius >= d && d >= abs(circles[i].radius - circles[j].radius) ){
                            unionSet(i, j);
                        }
                    }
                }
            }
        }
        
        sets = biggestSet();
        cout<<"The largest component contains "<<sets<<(sets == 1 ? " ring." : " rings.")<<endl;
    }
    
    
}
