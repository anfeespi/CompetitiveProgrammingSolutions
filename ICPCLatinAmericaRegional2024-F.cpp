    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main(){
        double n, k;
        string s = "";
        
        cin>>k>>n;
        
        if(n / k > 3.0){
            s = "*";
            n = 0;
        }
        
        while(n > 0){
            if(n == 1){
                s += "X";
                n--;
            } else if(n == 3*k){
                for(int i = 0; i < k; i++) s += "-X-";
                n = 0;
                k = 0;
            } else if(ceil(n / 2) >= k){
                s += "X-";
                n -= 2;
                k--;
            } else{
                s = "*";
                n = 0;
            }
        }
        
        cout<<s<<endl;
    }
