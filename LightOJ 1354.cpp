#include <bits/stdc++.h>

using namespace std;

int ip1[4]; 
string ip2[4], aux, temp;

int main(){
    int n, cases = 1;
    cin>>n;
    while(n--){
        scanf("%d.%d.%d.%d", &ip1[0], &ip1[1], &ip1[2], &ip1[3]);
        cin>>aux;
        istringstream ss(aux);
        int i = 0;
        while(getline(ss, temp, '.')) ip2[i++] = temp;
        
        bool equ = true;
        for(int i = 0; i < 4; i++){
            bitset<8> num(ip1[i]);
            bitset<8> bina(ip2[i]);
            
            if(num != bina){
                equ = false;
                break;
            }
        }
        
        cout<<"Case "<<cases++<<": "<<(equ ? "Yes" : "No")<<endl;
    }
}
