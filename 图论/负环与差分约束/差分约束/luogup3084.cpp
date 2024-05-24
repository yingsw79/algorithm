#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P3084

const int N = 200010, M = 600010;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], cnt[N], n, m, tot;
bool st[N];
deque<int> q;  //SLF(Small Label First)优化

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    q.push_back(0);
    st[0] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop_front();
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] > n || ++tot > 1926817) return -1;
                if (!st[j]) {
                    if (!q.empty() && dist[j] > dist[q.front()])
                        q.push_back(j);
                    else
                        q.push_front(j);
                    st[j] = true;
                }
            }
        }
    }
    return dist[n];
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a - 1, b, 1);
        add(b, a - 1, -1);
    }
    for (int i = 1; i <= n; i++) {
        add(i, i - 1, 0);
        add(i - 1, i, 1);
    }

    printf("%d\n", spfa());

    return 0;
}