#include <bits/stdc++.h>
using namespace std;

struct Proposal {
    string name;
    double price;
    int met_requirements;
    double compliance;
};

int main() {
    int n, p, rfp_number = 0;
    string line;

    while (cin>>n>>p && n != 0 && p != 0) {
        cin.ignore();
        rfp_number++;

        vector<string> requirements(n);
        for (int i = 0; i < n; i++) {
            getline(cin, requirements[i]);
        }

        vector<Proposal> proposals;
        for (int i = 0; i < p; i++) {
            string name;
            double price;
            int met;

            getline(cin, name);
            cin>>price>>met;
            cin.ignore();

            set<string> met_requirements;
            for (int j = 0; j < met; ++j) {
                string req;
                getline(cin, req);
                met_requirements.insert(req);
            }

            double compliance = static_cast<double>(met_requirements.size())/n;

            proposals.push_back({name, price, static_cast<int>(met_requirements.size()), compliance});
        }

        Proposal best_proposal = {"", numeric_limits<double>::max(), 0, -1.0};
        for (const auto& proposal : proposals) {
            if (proposal.compliance > best_proposal.compliance ||
                (proposal.compliance == best_proposal.compliance && proposal.price < best_proposal.price) ||
                (proposal.compliance == best_proposal.compliance && proposal.price == best_proposal.price &&
                 best_proposal.name.empty())) {
                best_proposal = proposal;
            }
        }

        if(rfp_number > 1) cout<<endl;
        cout<<"RFP #"<<rfp_number<<endl;
        cout<<best_proposal.name<<endl;
    }
}
