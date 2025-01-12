#include <bits/stdc++.h>

using namespace std;

class Team{
    public:
        string name;
        int points;
        int wins;
        int ties;
        int losses;
        int gs;
        int ga;
        
        int total_games(){
            return wins + ties + losses;
        }
        
        int goal_difference(){
            return gs - ga;
        }
};

bool comp(const Team& a, const Team& b){
    return a.points != b.points ? a.points > b.points :
            a.wins != b.wins ? a.wins > b.wins :
             a.gs - a.ga != b.gs - b.ga ? a.gs - a.ga > b.gs - b.ga :
              a.gs != b.gs ? a.gs > b.gs : 
               a.wins + a.ties + a.losses != b.wins + b.ties + b.losses ? a.wins + a.ties + a.losses < b.wins + b.ties + b.losses : lexicographical_compare(a.name.begin(), a.name.end(), b.name.begin(), b.name.end(), [](char c1, char c2) { return tolower(c1) < tolower(c2); });
}

vector<Team> tournament;
string current_tournament, aux, temp;
int t, n, g, gaux, gaux2;

int main(){
    string aux1, aux2;
    cin>>n;
    cin.ignore();
    while(n--){
        tournament.clear();
        getline(cin, current_tournament);
        cin>>t;
        cin.ignore();
        while(t--){
            getline(cin, aux);
            Team auxt;
            auxt.name = aux;
            auxt.points = 0;
            auxt.wins = 0;
            auxt.ties = 0;
            auxt.losses = 0;
            auxt.gs = 0;
            auxt.ga = 0;
            tournament.push_back(auxt);
        }
        
        cin>>g;
        cin.ignore();
        while(g--){
            getline(cin, aux);
            stringstream ss(aux);
            getline(ss, aux1, '#');
            getline(ss, temp, '@');
            gaux = stoi(temp);
            getline(ss, temp, '#');
            gaux2 = stoi(temp);
            getline(ss, aux2);
            
            auto pos1 = find_if(tournament.begin(), tournament.end(), [&aux1](const Team& team) {
                return team.name == aux1;
            });
            
            auto pos2 = find_if(tournament.begin(), tournament.end(), [&aux2](const Team& team) {
                return team.name == aux2;
            });
            
            if(gaux == gaux2){
                pos1->ties++;
                pos1->gs += gaux;
                pos1->ga += gaux2;
                pos1->points++;
                
                pos2->ties++;
                pos2->gs += gaux2;
                pos2->ga += gaux;
                pos2->points++;
            }else{
                if(gaux < gaux2){
                    swap(pos1, pos2);
                    swap(gaux, gaux2);
                }
                
                pos1->wins++;
                pos1->gs += gaux;
                pos1->ga += gaux2;
                pos1->points += 3;
                
                pos2->losses++;
                pos2->gs += gaux2;
                pos2->ga += gaux;
            }
        }
        
        sort(tournament.begin(), tournament.end(), &comp);
        
        cout<<current_tournament<<endl;
        g = 1;
        for(auto pair : tournament){
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", g, pair.name.c_str(), pair.points, pair.total_games(), pair.wins, pair.ties, pair.losses, pair.goal_difference(), pair.gs, pair.ga);
            g++;
        }
        
        if(n)
            cout<<endl;
    }

}
