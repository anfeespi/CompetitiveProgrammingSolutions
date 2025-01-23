#include <bits/stdc++.h>

using namespace std;

class Arr{
    public: string name;
    public: int b; 
    public: int CD;
    public: int d;
    public: pair<int,int> limits[1001];
    public: vector<int> cs;

    void calculate(){
        cs = vector<int>(d);
        
        cs[d] = CD;
        for(int i = d-1; i > 0; i--){
            cs[i] = cs[i+1] * (limits[i+1].second - limits[i+1].first + 1);
        }
        
        cs[0] = b;
        
        for(int i = 1; i <= d; i++){
            cs[0] -= cs[i] * limits[i].first;
        }
    }
    
    int pa(vector<int> sizs){
        int paaux = cs[0];
        for(int i = 1; i <= d; i++){
            paaux += cs[i]*sizs[i-1];
        }
        return paaux;
    }
};

int n, r, pos;
vector<int> auxV(11);
pair<int, int> aux;
string fid;

int main(){
    scanf("%d %d", &n, &r);
    vector<Arr> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].name>>a[i].b>>a[i].CD>>a[i].d;
        for(int j = 1; j <= a[i].d; j++){
            scanf("%d %d", &aux.first, &aux.second);
            a[i].limits[j] = aux;
        }
        a[i].calculate();
    }
    
    for(int i = 0; i < r; i++){
        cin>>fid;
        for(int j = 0; j < a.size(); j++)
            if(fid == a[j].name) pos = j;
        
        for(int j = 0; j < a[pos].d; j++)
            cin>>auxV[j];
        
        cout<<a[pos].name<<"[";
        
        for(int j = 0; j < a[pos].d - 1; j++)
            printf("%d, ", auxV[j]);
        
        printf("%d] = ", auxV[a[pos].d - 1]);
        printf("%d\n", a[pos].pa(auxV));
    }
}
