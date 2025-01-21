#include <bits/stdc++.h>

using namespace std;

bool isNumber(const string& c) {
    return all_of(c.begin(), c.end(), ::isdigit);
}

int main(){
    int n;
    cin>>n;
    string s;
    cin.ignore();
    cin.ignore();
    while(n--){
        string res;
        stack<string> operators;
        while(getline(cin, s) && s != ""){
            if(isNumber(s)){
                res+=s;
            }else if(s == "("){
                operators.push(s);
            }else if(s == ")"){
                while(!operators.empty() && operators.top() != "("){
                    res+=operators.top();
                    operators.pop();
                }
                if(operators.top() == "(") operators.pop();
            }else if(s == "+" || s == "-"){
                while(!operators.empty() && operators.top() != "("){
                    res+=operators.top();
                    operators.pop();
                }
                operators.push(s);
            }else if(s == "*" || s == "/"){
                while(!operators.empty() && (operators.top() == "*" || operators.top() == "/") && operators.top() != "("){
                    res+=operators.top();
                    operators.pop();
                }
                operators.push(s);
            }
        }
        while(!operators.empty()){
            res+=operators.top();
            operators.pop();
        }
        
        cout<<res<<endl;
        if(n > 0) cout<<endl;
    }
}
