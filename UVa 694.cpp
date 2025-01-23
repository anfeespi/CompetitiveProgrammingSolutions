#include <iostream>

using namespace std;

int main()
{
    long c = 0;
    long a, l;
    while(cin>>a>>l){
        
        c++;
        if(a<0 && l<0){
            break;
        }
        long a1=a;
        long t=1;
        
        while(a1>1){
            if(a1%2!=0){
                a1 = 3*a1+1;
                if(a1>l){
                    break;
                }
                
                
            }
            else{
                a1 = a1/2;
            }
            t++;
        }
        cout<<"Case "<<c<<": A = "<<a<<", limit = "<<l<<", number of terms = "<<t<<endl;
    }
}


