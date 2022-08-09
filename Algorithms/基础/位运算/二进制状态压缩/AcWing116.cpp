#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;

int change[4][4];
int state;

int get(int x, int y) {
    return x * 4 + y;
}

int init = []() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++)
                change[i][j] += (1 << get(i, k)) + (1 << get(k, j));
            change[i][j] -= 1 << get(i, j);
        }
    return 0;
}();

int main() {
    for (int i = 0; i < 4; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 4; j++) {
            state += (line[j] == '+') << get(i, j);
        }
    }

    vector<PII> res;
    for (int i = 0; i < 1 << 16; i++) {
        int cur = state;
        vector<PII> tmp;
        for (int j = 0; j < 16; j++) {
            if (i >> j & 1) {
                int x = j / 4, y = j % 4;
                cur ^= change[x][y];
                tmp.push_back({x, y});
            }
        }
        if (!cur && (res.empty() || res.size() > tmp.size())) res = tmp;
    }

    cout << res.size() << endl;
    for (auto& p : res) cout << p.first + 1 << ' ' << p.second + 1 << endl;

    return 0;
}