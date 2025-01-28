#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-9;

bool isEqual(double a, double b) {
    return fabs(a - b) < EPS;
}

int main() {
    double x1, y1, x2, y2;

    while (cin>>x1>>y1>>x2>>y2) {
        double mx = (x1 + x2) / 2.0;
        double my = (y1 + y2) / 2.0;

        double dx = (y1 - y2) / 2.0;
        double dy = (x2 - x1) / 2.0;

        double ax1 = mx + dx;
        double ay1 = my + dy;
        double ax2 = mx - dx;
        double ay2 = my - dy;

        if (isEqual(hypot(x1 - ax1, y1 - ay1), hypot(x1 - ax2, y1 - ay2)) && isEqual(hypot(x2 - ax1, y2 - ay1), hypot(x2 - ax2, y2 - ay2)))
            cout<<fixed<< setprecision(10)<<ax1<<" "<<ay1<<" "<<ax2<<" "<<ay2<<endl;
        else
            cout << "Impossible" << endl;
    }
}
