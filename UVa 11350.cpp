#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    while(n--){
        long izqn = 0, izqd = 1;
        long dern = 1, derd = 0;
        long nf = 1, df = 1;

        string cad = "";
        cin>>cad;

        for(int i = 0; i < cad.length(); i++){
            if(cad[i] == 'R'){
                izqn += dern;
                izqd += derd;

                nf += dern;
                df += derd;
            }else if(cad[i] == 'L'){
                dern += izqn;
                derd += izqd;

                nf += izqn;
                df += izqd;
            }
        }

        cout<<nf<<"/"<<df<<endl;

    }

}
