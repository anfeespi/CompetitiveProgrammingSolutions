#include <iostream>

using namespace std;

int main()
{
    int casos = 1;
    while(true){
        int n,m,c, fusible=0, maximo=0;
        bool quemado = false;
        cin>>n>>m>>c;
        int devices[n];
        bool encendido[n];
        if(n==0 && m==0 && c==0) break;
        
        for(int i=0; i<n; i++) cin>>devices[i];
        for(int i=0; i<n; i++) encendido[i]=false;
        
        while(m--){
            int aux;
            cin>>aux;
            if(encendido[aux-1] == false) {
                fusible += devices[aux-1];
                encendido[aux-1] = true;
            }
            else {
                fusible -= devices[aux-1];
                encendido[aux-1] = false;
            }
            
            if(fusible>c) quemado = true;
            if(fusible>maximo) maximo = fusible;
        }
        cout<<"Sequence "<<casos<<endl;
        if(quemado) cout<<"Fuse was blown."<<endl;
        else cout<<"Fuse was not blown."<<endl<<"Maximal power consumption was "<<maximo<<" amperes."<<endl;
        cout<<endl;
        casos++;
    }
}
