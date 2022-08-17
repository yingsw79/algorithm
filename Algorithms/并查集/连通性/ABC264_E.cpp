#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

// https://atcoder.jp/contests/abc264/tasks/abc264_e
//1.虚拟源点 2.顺序删边转化为逆序加边 3.用并查集维护虚拟节点所在连通块的大小

const int N = 1e6 + 10;
int p[N], cnt[N];
bool st[N];    //标记边
int query[N];  //询问
PII g[N];      //边

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) p[i] = i, cnt[i] = 1;

    for (int i = n + 1; i <= n + m; i++) {
        p[i] = 0;  //发电站的祖先全搞成超级源点0
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d%d", &g[i].first, &g[i].second);
    }
    int q;
    cin >> q;

    for (int i = 1; i <= q; i++) {
        int x;
        scanf("%d", &x);
        st[x] = true;
        query[i] = x;
    }

    for (int i = 1; i <= k; i++) {
        int a = g[i].first, b = g[i].second;
        if (!st[i]) {
            a = find(a), b = find(b);
            if (a != b) {
                if (a == 0) swap(a, b);  //这里是为了把cnt都累加到超级源点上
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
    }
    //一次加边
    vector<int> ans;
    for (int i = q; i >= 1; i--) {
        int x = query[i];
        int a = g[x].first, b = g[x].second;
        ans.push_back(cnt[0]);
        //把这边加入
        a = find(a), b = find(b);
        if (a != b) {
            if (a == 0) swap(a, b);
            p[a] = b;
            cnt[b] += cnt[a];
        }
    }
    reverse(ans.begin(), ans.end());

    for (auto c : ans) {
        printf("%d\n", c);
    }

    return 0;
}