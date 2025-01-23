#include <bits/stdc++.h>

using namespace std;

class line{
    public: pair<double, double> b;
    public: pair<double, double> e;
    public: double refrac;
};

bool isIn(double xini, double xend, double pi, double pe){
    if(xini > xend){
        swap(xini, xend);
    }
    return (xini <= pi && pi <= xend) && (xini <= pe && pe <= xend);
}

set<double> xaxis;
vector<line> lines(100001);
vector<pair<double, double>> limits(1000);
int t, n, i, j, limit;
double pr;

int main(){
    xaxis.clear();
    lines.clear();
    
    cin>>t;
    while(t--){
        xaxis.clear();
        cin>>n;
        for(i = 0; i < n; i++){
            cin>>lines[i].b.first>>lines[i].b.second>>lines[i].e.first>>lines[i].e.second>>lines[i].refrac;
            xaxis.insert(lines[i].b.first);
            xaxis.insert(lines[i].e.first);
        }
        
        limit = 0;
        for(auto it : xaxis){
            if(limit != 0){
                limits[limit - 1].second = it;
            }
            limits[limit].first = it;
            limit++;
        }
        
        printf("%d\n", limit+1);
        printf("-inf %.3lf %.3lf\n", limits[0].first, (1.0));
        pr = 1;
        for(j = 0; j < limit-1; j++){
            pr = 1;
            for(i = 0; i < n; i++){
                if(isIn(lines[i].b.first, lines[i].e.first, limits[j].first, limits[j].second)){
                    pr *= lines[i].refrac;
                }
            }
            printf("%.3lf %.3lf %.3lf\n", limits[j].first, limits[j].second, pr);
        }
        printf("%.3lf +inf %.3lf\n", limits[j].first, (1.0));
        if(t)
            puts("");
    }
}
