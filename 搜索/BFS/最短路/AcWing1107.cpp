#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dist;  //用哈希表记录状态
unordered_map<string, pair<char, string> > pre;  //记录每个状态的前驱操作和状态
string start = "12348765", eend, res;

string get(string t, int op) {
    string k;
    if (op == 0)
        k = {t[4], t[5], t[6], t[7], t[0], t[1], t[2], t[3]};
    else if (op == 1)
        k = {t[3], t[0], t[1], t[2], t[7], t[4], t[5], t[6]};
    else
        k = {t[0], t[5], t[1], t[3], t[4], t[6], t[2], t[7]};
    return k;
}


int bfs() {
    queue<string> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        if (t == eend) return dist[t];
        for (int i = 0; i < 3; i++) {
            string s = get(t, i);
            if (!dist.count(s)) {
                dist[s] = dist[t] + 1;
                pre[s] = {'A' + i, t};
                q.push(s);
            }
        }
    }
}

int main() {
    char a[10];
    for (int i = 1; i <= 8; i++) cin >> a[i];

    reverse(a + 5, a + 8 + 1);
    for (int i = 1; i <= 8; i++) eend.push_back(a[i]);
    cout << bfs() << endl;
    while (eend != start) {
        res += pre[eend].first;
        eend = pre[eend].second;
    }
    reverse(res.begin(), res.end());
    cout << res;
}
