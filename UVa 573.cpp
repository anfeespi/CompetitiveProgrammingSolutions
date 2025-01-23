#include <bits/stdc++.h>

using namespace std;

double h, u, d, f, ah, cr, cd, day;

void simulate(){
    ah = 0;
    day = 0;
    cd = u;
    f = u*(f/100);
    while(true){
        ah += (u - (day*f) ) < 0 ? 0 : (u - (day*f) );
        day++;
        if(ah > h){
            printf("success on day %.0f\n", day);
            return;
        }
        ah -= d;
        if(ah < 0){
            printf("failure on day %.0f\n", day);
            return;
        }
    }
}

int main(){
    while(cin>>h>>u>>d>>f && h != 0){
        simulate();
    }
}
