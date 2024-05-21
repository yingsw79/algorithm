#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/241/

const int N = 10010;
int p[N], d[N], idx;
unordered_map<int, int> mp;

int get(int x) {
    if (!mp.count(x)) mp[x] = idx++;
    return mp[x];
}

int find(int x) {
    if (p[x] == x) return x;
    int root = find(p[x]);
    d[x] ^= d[p[x]];
    return p[x] = root;
}

int main() {
    for (int i = 0; i < N; i++) p[i] = i;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int l, r;
        char op[5];
        scanf("%d%d%s", &l, &r, op);
        l = get(l - 1), r = get(r);
        int a = find(l), b = find(r), t = (*op == 'o');
        if (a != b) {
            p[a] = b;
            d[a] = d[l] ^ d[r] ^ t;  //无向合并
        } else if (d[l] ^ d[r] ^ t) {
            printf("%d\n", i - 1);
            return 0;
        }
    }
    printf("%d\n", m);

    return 0;
}