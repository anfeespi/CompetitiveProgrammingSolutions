#include <bits/stdc++.h>

using namespace std;

vector<int> arr(6);

int main(){
    int n;
    string line;
    cin>>n;
    cin.ignore();
    while(n--){
        fill(arr.begin(), arr.end(), 0);
        getline(cin, line);
        
        for(int i = 0; i < line.length(); i++){
            switch(line[i]){
                case 'M':
                    arr[0]++;
                    break;
                case 'A':
                    arr[1]++;
                    break;
                case 'R':
                    arr[2]++;
                    break;
                case 'G':
                    arr[3]++;
                    break;
                case 'I':
                    arr[4]++;
                    break;
                case 'T':
                    arr[5]++;
                    break;
            }
        }
        
        arr[1] /= 3;
        arr[2] /= 2;
        
        cout<<*min_element(arr.begin(), arr.end())<<endl;
        
    }
}
