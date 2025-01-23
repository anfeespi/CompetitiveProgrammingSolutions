#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> encoding;

vector<string> in, enc;
string aux;

void preset(){
    vector<char> aux = {'A', 'E', 'I', 'O', 'U', 'Y', 'W', 'H'};
    encoding.push_back(aux);
    aux = { 'B', 'P', 'F', 'V' };
    encoding.push_back(aux);
    aux = { 'C', 'S', 'K', 'G', 'J', 'Q', 'X', 'Z' };
    encoding.push_back(aux);
    aux = { 'D', 'T' };
    encoding.push_back(aux);
    aux = { 'L' };
    encoding.push_back(aux);
    aux = { 'M', 'N' };
    encoding.push_back(aux);
    aux = { 'R' };
    encoding.push_back(aux);
}

string calculate(string toCalc){
    string ret = "", dev = "";
    int i = 0;
    bool pass = false;
    
    while(i < toCalc.length()){
        pass = false;
        for(int k = 0; k <= 6; k++){
            for(int j = 0; j < encoding[k].size(); j++){
                if(toCalc[i] == encoding[k][j]){
                    ret += to_string(k);
                    pass = true;
                    break;
                }
            }
            if(pass) break;
        }
        i++;
    }
    
    char act = ret[0];
    for(i = 1; i < ret.length(); i++){
        if(ret[i] != act){
            dev += act;
            act = ret[i];
        }
        
        if(i == ret.length()-1){
            dev += ret[i];
        }
    }
    
    ret = dev[0];
    
    for(i = 1; i < dev.length(); i++){
        if(dev[i] != '0'){
            ret += dev[i];
        }
    }
    
    ret[0] = toCalc[0];
    
    if(ret.length() < 4){
        for(int i = ret.length(); i < 4; i++){
            ret += "0";
        }
    }
    
    if(ret.length() > 4){
        ret = ret.substr(0,4);
    }
    
    return ret;
}

string fillSpaces(int end, int dest){
    string spaces = "";
    for(int i = 0; i < (dest-end); i++){
        spaces += " ";
    }
    return spaces;
}


int main()
{
    preset();
    cout<<fillSpaces(0, 9)<<"NAME"<<fillSpaces(13, 34)<<"SOUNDEX CODE"<<endl;
    while(cin>>aux){
        cout<<fillSpaces(0, 9)<<aux<<fillSpaces(9+aux.length(), 34)<<calculate(aux)<<endl;
    }
    cout<<fillSpaces(0,19)<<"END OF OUTPUT"<<endl;
    
}
