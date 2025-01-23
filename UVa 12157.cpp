#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int caso=1; caso<=t; caso++){
        int n, contm = 0, contj = 0;
        cin>>n;
        while(n--){
            int aux;
            cin>>aux;
            int auxm = aux, auxj = aux;
            while(auxm>=0){
                auxm -= 30;
                contm += 10;
            }
            while(auxj>=0){
                auxj -= 60;
                contj += 15;
            }
        }
        cout<<"Case "<<caso<<": ";
        if(contm<contj) cout<<"Mile "<<contm<<endl;
        else if(contj<contm) cout<<"Juice "<<contj<<endl;
        else cout<<"Mile Juice "<<contm<<endl;
    }
}
