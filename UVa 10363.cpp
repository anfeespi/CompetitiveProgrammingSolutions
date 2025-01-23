#include <bits/stdc++.h>

using namespace std;
    
string grid[3];
int t, x, o, i, j;
bool winx, wino;

int main(){
    cin>>t;
    while(t--){
        x = o = 0;
        winx = wino = false;
        for(i = 0; i < 3; i++){
            cin>>grid[i];
            for(j = 0; j < 3; j++){
                if(grid[i][j] == 'X') x++;
                else if(grid[i][j] == 'O') o++;
            }
        }
        
        for(i = 0; i < 3; i++){
            if(grid[i][0] == 'X' && grid[i][1] == 'X' && grid[i][2] == 'X') winx = true;
            if(grid[i][0] == 'O' && grid[i][1] == 'O' && grid[i][2] == 'O') wino = true;
        }
        
        for(i = 0; i < 3; i++){
            if(grid[0][i] == 'X' && grid[1][i] == 'X' && grid[2][i] == 'X') winx = true;
            if(grid[0][i] == 'O' && grid[1][i] == 'O' && grid[2][i] == 'O') wino = true;
        }
        
        if(grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') winx = true;
        if(grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X') winx = true;
        
        if(grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O') wino = true;
        if(grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O') wino = true;

        
        if(wino && winx) cout<<"no";
        else if(wino && o != x) cout<<"no";
        else if(winx && x <= o) cout<<"no";
        else if(x-o != 0 && x-o != 1) cout<<"no";
        else cout<<"yes";
        cout<<endl;
    }
    
}
