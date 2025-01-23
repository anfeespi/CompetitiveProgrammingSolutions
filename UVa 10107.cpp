#include<bits/stdc++.h>

using namespace std;

int uebfa[10001];

int main(){
    int i = 1;
    while(scanf("%d", &uebfa[i]) != EOF){
        sort(uebfa, uebfa + i + 1);

        if(i == 1)
            printf("%d\n",uebfa[1]);

        else if(i%2 == 0)
            printf("%d\n",(uebfa[i/2] + uebfa[i/2 + 1]) / 2);

        else
            printf("%d\n",uebfa[i/2 + 1]);
        i++;
    }
}
