#include <bits/stdc++.h>

using namespace std;

int n, k, m;
char aux;
double auxd;
string auxs;
map<char, double> letters;

int main(){
    cin>>n;
    while(n--){
        cin>>k;
        letters.clear();
        while(k--){
            cin>>aux>>auxd;
            auxd /= 100;
            letters[aux] = auxd;
        }
        
        cin.ignore();
        auxd = 0;
        
        cin>>m;
        m++;
        while(m--){
            getline(cin, auxs);
            for(int i = 0; i < auxs.length(); i++)
                auxd += letters[auxs[i]];
        }
        
        cout<<fixed<<setprecision(2)<<auxd<<"$"<<endl;
    }
}
