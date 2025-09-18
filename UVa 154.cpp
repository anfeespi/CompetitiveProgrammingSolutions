//It can be so much better but i thinked it very quickly T.T 
#include <bits/stdc++.h>

using namespace std;

class Bin {
    public:
    char red;
    char orange;
    char yellow;
    char green;
    char blue;
};

vector<Bin> cities(100);
string s;
int l, mchanges, crrchanges = 0, crridx = -1;

int total_changes(Bin& a, Bin& b){
    int sum = 0;
    if(a.red != b.red) sum++;
    if(a.orange != b.orange) sum++;
    if(a.yellow != b.yellow) sum++;
    if(a.green != b.green) sum++;
    if(a.blue != b.blue) sum++;
    
    return sum;
}

int main(){
    l = 0;
    while(getline(cin, s)){
        if(s == "e" || s == "#"){
            if(s == "#" && l == 0) return 0;
            mchanges = INT_MAX;
            crridx = -1;
            for(int i = 0; i < l; i++){
                crrchanges = 0;
                for(int j = 0; j < l; j++){
                    if(i != j) crrchanges += total_changes(cities[i], cities[j]);
                }
                
                if (crrchanges < mchanges){
                    crridx = i;
                    mchanges = crrchanges;
                }
            }
            
            cout<<crridx+1<<endl;
            l = 0;
            if(s == "#") return 0;
            if(s == "e") continue;
        }else if(s.length() > 1 && !(s.find("/") != std::string::npos)){
            continue;
        }
        
        Bin aux;
        
        for(int i = 0; i < 17; i += 4){
            switch(s[i]){
                case 'r':
                    aux.red = s[i+2];
                    break;
                case 'o':
                    aux.orange = s[i+2];
                    break;
                case 'y':
                    aux.yellow = s[i+2];
                    break;
                case 'g':
                    aux.green = s[i+2];
                    break;
                case 'b':
                    aux.blue = s[i+2];
                    break;
            }
        }
        cities[l] = aux;
        l++;
    }    
    
}
