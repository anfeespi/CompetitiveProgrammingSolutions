#include <bits/stdc++.h>

using namespace std;

int n, i, j, k, mx, cont;

int main(){
    while(scanf("%d %d", &i, &j) != EOF){
        mx = 0;
        for(n = min(i,j); n <= max(i,j); n++){
            k = n, cont = 1;
            while(k > 1){
                k = ((k&1) == 0) ? k/2 : (3*k)+1;
                cont++;
            }
            mx = max(mx, cont);
        }
        printf("%d %d %d\n", i, j, mx);
    }
}
