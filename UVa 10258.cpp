#include <bits/stdc++.h>

using namespace std;

class Team {
public:
    int num;
    vector<int> problems = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<bool> solved = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    int total() {
        int s = 0;
        for (int i = 0; i < 9; i++) {
            if (solved[i])
                s += problems[i];
        }
        return s;
    }

    int s_problems() {
        return count(solved.begin(), solved.end(), true);
    }
};

bool comp(Team &a, Team &b) {
    if (a.s_problems() != b.s_problems()) 
        return a.s_problems() > b.s_problems();
    if (a.total() != b.total()) 
        return a.total() < b.total();
    return a.num < b.num;
}

vector<Team> contest;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();

    while (n--) {
        contest.clear();
        string line;

        while (getline(cin, line) && !line.empty()) {
            stringstream ss(line);
            int c, p, t;
            char l;
            ss >> c >> p >> t >> l;

            auto it = find_if(contest.begin(), contest.end(), [c](const Team &team) {
                return team.num == c;
            });

            if (it == contest.end()) {
                Team aux;
                aux.num = c;
                contest.push_back(aux);
                it = contest.end() - 1;
            }

            if (l == 'C' && !it->solved[p - 1]) {
                it->solved[p - 1] = true;
                it->problems[p - 1] += t;
            } else if (l == 'I' && !it->solved[p - 1]) {
                it->problems[p - 1] += 20;
            }
        }

        sort(contest.begin(), contest.end(), comp);

        for (auto &team : contest) {
            printf("%d %d %d\n", team.num, team.s_problems(), team.total());
        }

        if (n > 0) 
            printf("\n");
    }

    return 0;
}
