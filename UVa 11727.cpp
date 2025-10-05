#include <bits/stdc++.h>

using namespace std;

vector<int> nums(3);

int main(){
    int t, casen = 1;
    cin>>t;
    
    while(t--){
        for(int i = 0; i < 3; i++) cin>>nums[i];
        
        sort(nums.begin(), nums.end());
        
        cout<<"Case "<<casen++<<": "<<nums[1]<<endl;
    }
    
}
