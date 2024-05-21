#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P1197

const int N = 400010;
int p[N];
int n, m, k;
int query[N];
bool st[N];
int h[N], e[N], ne[N], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        st[x] = true;
        query[i] = x;
    }

    int cnt = n - k;
    for (int i = 0; i < idx; i += 2) {
        int a = e[i], b = e[i ^ 1];  //无向图双向边成对
        if (!st[a] && !st[b]) {
            a = find(a), b = find(b);
            if (a != b) {
                p[a] = b;
                cnt--;
            }
        }
    }

    vector<int> res;
    res.push_back(cnt);
    for (int i = k; i; i--) {
        int x = query[i];
        cnt++;  //增加一个点,连通块数量加1
        st[x] = false;  //点恢复正常
        int a = find(x);
        for (int j = h[x]; ~j; j = ne[j]) {
            int k = e[j];
            if (st[k]) continue;
            int b = find(k);
            if (a != b) {
                p[b] = a;  //注意顺序
                cnt--;
            }
        }
        res.push_back(cnt);
    }

    reverse(res.begin(), res.end());
    for (auto& x : res) {
        printf("%d\n", x);
    }

    return 0;
}