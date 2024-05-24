#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int B = 10000;
vector<int> V(3);
unordered_set<ll> st;
unordered_set<int> res;

ll get(vector<int>& v) { return v[0] * B * B + v[1] * B + v[2]; }

void pour(vector<int>& v, int i, int j) {
    int t = min(v[i], V[j] - v[j]);
    v[i] -= t, v[j] += t;
}

void dfs(vector<int> v) {
    st.insert(get(v));
    res.insert(v[2]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                vector<int> tmp = v;
                pour(tmp, i, j);
                if (!st.count(get(tmp))) {
                    dfs(tmp);
                }
            }
        }
    }
}

int main() {
    while (cin >> V[0] >> V[1] >> V[2]) {
        st.clear();
        res.clear();
        vector<int> v{0, 0, V[2]};
        dfs(v);
        cout << res.size() << endl;
    }
    return 0;
}
