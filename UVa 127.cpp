#include <bits/stdc++.h>

using namespace std;

bool compCards(string a, string b){
    return a[0] == b[0] || a[1] == b[1];
}

string s;

int main(){
    while(cin>>s && s != "#"){
        vector<stack<string>> cards(52);
        
        cards[0].push(s);
        for(int i = 1; i < 52; i++){
            cin>>s;
            cards[i].push(s);
        }
        
        bool move;
        do{
            move = false;
            for(int i = 1; i < cards.size(); i++){
                if(i >= 3 && compCards(cards[i].top(), cards[i-3].top())){
                    cards[i-3].push(cards[i].top());
                    cards[i].pop();
                    
                    move = true;
                    if(cards[i].empty())
                        cards.erase(cards.begin()+i);
                    break;
                }else if(compCards(cards[i].top(), cards[i-1].top())){
                    cards[i-1].push(cards[i].top());
                    cards[i].pop();
                    
                    move = true;
                    if(cards[i].empty())
                        cards.erase(cards.begin()+i);
                    break;
                }
            }
        }while(move);
        
        
        int sz = cards.size();
        
        cout<<sz;
        if(sz == 1)
            cout<<" pile ";
        else
            cout<<" piles ";
        
        cout<<"remaining: ";
        
        for(int i = 0; i < cards.size(); i++){
            if(i > 0) cout<<" ";
            cout<<cards[i].size();
        }
        cout<<endl;
    }
}
