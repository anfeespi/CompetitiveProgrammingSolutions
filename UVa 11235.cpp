#include <bits/stdc++.h>

using namespace std;

struct Node {
    int left_val, right_val, left_count, right_count, max_count;
};

vector<int> a;
vector<int> first_occurrence;
vector<int> last_occurrence;
vector<Node> tree;

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = {a[start], a[start], 1, 1, 1};
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    Node left_child = tree[2 * node];
    Node right_child = tree[2 * node + 1];

    tree[node].left_val = left_child.left_val;
    tree[node].right_val = right_child.right_val;
    tree[node].left_count = left_child.left_count;
    tree[node].right_count = right_child.right_count;

    tree[node].max_count = max(left_child.max_count, right_child.max_count);

    if (left_child.right_val == right_child.left_val) {
        int combined_count = left_child.right_count + right_child.left_count;
        tree[node].max_count = max(tree[node].max_count, combined_count);

        if (left_child.left_val == left_child.right_val) {
            tree[node].left_count = combined_count;
        }
        if (right_child.left_val == right_child.right_val) {
            tree[node].right_count = combined_count;
        }
    }
}

Node rmq(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return {0, 0, 0, 0, 0};
    }

    if (l <= start && end <= r) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    Node p1 = rmq(2 * node, start, mid, l, r);
    Node p2 = rmq(2 * node + 1, mid + 1, end, l, r);

    if (p1.max_count == 0) return p2;
    if (p2.max_count == 0) return p1;

    Node res;
    res.left_val = p1.left_val;
    res.right_val = p2.right_val;
    res.left_count = p1.left_count;
    res.right_count = p2.right_count;
    res.max_count = max(p1.max_count, p2.max_count);

    if (p1.right_val == p2.left_val) {
        res.max_count = max(res.max_count, p1.right_count + p2.left_count);
        if (p1.left_val == p1.right_val) {
            res.left_count = p1.left_count + p2.left_count;
        }
        if (p2.left_val == p2.right_val) {
            res.right_count = p1.right_count + p2.right_count;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    while(cin>>n && n != 0) {
        cin>>q;
        a.resize(n);
        first_occurrence.assign(200001, -1);
        last_occurrence.assign(200001, -1);
        
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            a[i] += 100000;
            if (first_occurrence[a[i]] == -1) {
                first_occurrence[a[i]] = i;
            }
            last_occurrence[a[i]] = i;
        }

        tree.resize(4 * n);
        build(1, 0, n - 1);

        for (int k = 0; k < q; ++k) {
            int i, j;
            cin>>i>>j;
            i--; j--;

            int max_freq = 0;

            if (a[i] == a[j]) {
                max_freq = j - i + 1;
            } else {
                int first_val_end = last_occurrence[a[i]];
                int last_val_start = first_occurrence[a[j]];
                
                max_freq = max(first_val_end - i + 1, j - last_val_start + 1);

                if (first_val_end + 1 <= last_val_start - 1) {
                    Node result = rmq(1, 0, n - 1, first_val_end + 1, last_val_start - 1);
                    max_freq = max(max_freq, result.max_count);
                }
            }
            cout<<max_freq<<endl;
        }
    }
}
