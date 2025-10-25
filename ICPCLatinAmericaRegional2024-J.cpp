#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846
using namespace std;

vector<pair<double, double>> lines;
vector<pair<int, int>> flatpersons;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int angle, n, x, j;
    double sum = 0;
    
    cin>>angle>>n;
    
    flatpersons.resize(n, make_pair(0, 0));
    
    for(int i = 0; i < n; i++) cin>>flatpersons[i].first>>flatpersons[i].second;
    
    sort(flatpersons.begin(), flatpersons.end());
    
    for(int i = 0; i < n; i++){
        if(lines.size() == 0){
            lines.push_back(make_pair(flatpersons[i].first, flatpersons[i].first + flatpersons[i].second * tan((90 - angle) * (M_PI / 180.0))));
        }else{
            j = lines.size() - 1;
            
            if(lines[j].second >= flatpersons[i].first){
                lines[j].second = max(lines[j].second, flatpersons[i].first + flatpersons[i].second * tan((90 - angle) * (M_PI / 180.0)));
            } else {
                lines.push_back(make_pair(flatpersons[i].first, flatpersons[i].first + flatpersons[i].second * tan((90 - angle) * (M_PI / 180.0))));
            }
        }
    }
    
    for(int i = 0; i < lines.size(); i++){
        sum += lines[i].second - lines[i].first;
    }
    
    cout<<fixed<<setprecision(8)<<sum;
    
}
