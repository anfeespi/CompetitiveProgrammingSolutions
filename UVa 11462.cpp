#include<bits/stdc++.h>

using namespace std;

void sorted(int arr[], int n) {
    int output[n];
    int counting[101];
    memset(counting, 0, sizeof (counting));
    
    for (int i = 0; i < n; i++)
        counting[arr[i]]++;

    for (int i = 1; i <= 100; i++)
        counting[i] += counting[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[counting[arr[i]] - 1] = arr[i];
        counting[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++) 
        arr[i] = output[i];
}

int n, x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin>>n && n != 0){
        int arr[n];
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        
        sorted(arr, n);
        
        for(int i = 0; i < n; i++){
            if(i > 0) cout<<" ";
            cout<<arr[i];
        }
        
        cout<<endl;
    }
}
