#include <iostream>

using namespace std;

int main()
{
    int t, n = 0;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        int m = 0;
        int c[n];
        for(int e=0; e<n; e++){
            cin>>c[e];
        }
        for(int j=0; j<n; j++){
            if(c[j] > m){
			m = c[j];
		}
        }
        cout<<"Case "<<i+1<<": "<<m<<endl;
    }
    
}
