#include <bits/stdc++.h>

using namespace std;

set<int> d;

int main() {
	int t, cases = 1, x, y, n, w, tot;
	cin>>t;
	while(t--) {
		d.clear();
		tot = 1;
		cin>>n>>w;
		while(n--) {
			cin>>x>>y;
			d.insert(y);
		}

		int ini = *d.begin();
		for(auto it : d) {
			if(it - ini > w) {
				tot++;
				ini = it;
			}
		}

		cout<<"Case "<<cases++<<": "<<tot<<endl;
	}
}
