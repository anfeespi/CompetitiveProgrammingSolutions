#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    cin.ignore();
    while (n--) {
        string par;
        getline(cin, par);

        stack<char> eval;

        for (int i = 0; i < par.length(); i++){
            if(par[i] == '(' || par[i] == '['){
                eval.push(par[i]);
            }else{
                if(eval.empty()) {
                    eval.push('a');
                    break;
                }else if ((par[i] == ')' && eval.top() == '(') || (par[i] == ']' && eval.top() == '[')) {
                    eval.pop();
                } else {
                    eval.push('a');
                    break;
                }
            }
        }
        if(eval.empty())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
