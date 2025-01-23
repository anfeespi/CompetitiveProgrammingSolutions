#include<bits/stdc++.h>

using namespace std;

int32_t x, y;
uint32_t aux;

int main(){
    
    while(cin>>x){
        aux = static_cast<uint32_t>(x);
        bitset<32> in(aux), out;
        
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 8; j++)
                out[i*8 + j] = in[(3-i)*8 + j];
        
        aux = out.to_ulong();
        y = static_cast<int32_t>(aux);
        cout<<x<<" converts to "<<y<<endl;
    }
}
