#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100010, M = 300010;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
LL dist[N];
int cnt[N];
bool st[N];
stack<int> q;  //用栈代替队列

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() {
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;
    q.push(0);
    st[0] = true;

    while (q.size()) {
        int t = q.top();
        q.pop();
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] < dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n + 1) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--) {
        int x, a, b;
        scanf("%d%d%d", &x, &a, &b);
        if (x == 1)
            add(b, a, 0), add(a, b, 0);
        else if (x == 2)
            add(a, b, 1);
        else if (x == 3)
            add(b, a, 0);
        else if (x == 4)
            add(b, a, 1);
        else
            add(a, b, 0);
    }

    for (int i = 1; i <= n; i++) add(0, i, 1);

    if (spfa())
        puts("-1");
    else {
        LL res = 0;
        for (int i = 1; i <= n; i++) res += dist[i];
        printf("%lld\n", res);
    }

    return 0;
}
