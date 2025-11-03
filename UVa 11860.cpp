#include <bits/stdc++.h>
#define DBG(x) cout<<#x<<" = "<<(x)<<endl

using namespace std;

regex word_pattern("[a-z]+");
string line, aux;
vector<int> document;
map<string, int> words;
int t, p, q, total, doc = 1, auxp, auxq, bl;

int main(){
    scanf("%d", &t);
    
    while(t--){
        words.clear();
        document.clear();
        total = 0;
        
        while(getline(cin, line) && line != "END"){
            sregex_iterator crrmatch(line.begin(), line.end(), word_pattern);
            sregex_iterator lastmatch;
            
            while(crrmatch != lastmatch){
                smatch match = *crrmatch;
                aux = match.str();
                if (words.count(aux) == 0) words[aux] = total++;
                
                document.push_back(words[aux]);
                crrmatch++;
            }
        }
        
        vector<int> freq(total, 0);
        int have = 0, need = total;
        bl = INT_MAX, auxp = 0, auxq = 0;
        p = 0;
        
        for (q = 0; q < document.size(); q++) {
            int id = document[q];
            if (freq[id] == 0) have++;
            freq[id]++;

            while (have == need) {
                if (q - p < bl) {
                    bl = q - p;
                    auxp = p;
                    auxq = q;
                }

                int left_id = document[p];
                freq[left_id]--;
                if (freq[left_id] == 0) have--;
                p++;
            }
        }
        
        cout<<"Document "<<doc++<<": "<<auxp+1<<" "<<auxq+1<<endl;
    }
}
