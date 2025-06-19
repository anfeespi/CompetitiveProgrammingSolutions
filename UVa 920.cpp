#include <bits/stdc++.h>

using namespace std;

class Point{
    public:
        int x;
        int y;
};

bool comp(const Point& a, const Point& b){
    return a.x < b.x;
}

vector<Point> points;

int main(){
    int c, n, hmax, pos, t, i;
    double yi, yi1, xi, xi1, m, x, s, b;
    
    cin>>c;
    
    while(c--){
        points.clear();
        cin>>n;
        t = n;
        while(n--){
            Point paux;
            cin>>paux.x>>paux.y;
            points.push_back(paux);
        }
        
        sort(points.begin(), points.end(), &comp);
        
        hmax = 0;
        s = 0;
        i = t - 1;
        while(i != -1){
            yi = points[i].y;
            
            if(yi > hmax){
                xi = points[i].x;
                yi1 = points[i+1].y;
                xi1 = points[i+1].x;
                
                m = (yi1 - yi) / (xi1 - xi);
                b = yi - m*xi;
                x = (hmax - b) / m;
                s += sqrt( pow(x - xi, 2) + pow(yi - hmax, 2) );
                hmax = yi;
            }
            
            i--;
        }
        cout<<fixed<<setprecision(2)<<s<<endl;
    }
}
