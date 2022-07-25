#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1010, M = 10000 + 10000 + 1000 + 10, INF = 0x3f3f3f3f;

int n, m1, m2;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
int q[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
/* 
spfa求最短路的三种情况：
1. 无解：等价于有负环，spfa判负环可以将所有的点加入到队列中进行判断。
2. 奶牛1 和 奶牛n 的距离可以任意大，说明题目中给的约束关系并没有对他们两个造成影响，也就是说
奶牛1 和 奶牛n 是不联通的两个节点， dist[n] = INF;
3. 奶牛1 和 奶牛n 之间有通路， 可以求出最短路。 
*/

bool spfa(int size) {
    int hh = 0, tt = 0;
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);

    for (int i = 1; i <= size; i++) {
        q[tt++] = i;
        dist[i] = 0;
        st[i] = true;
    }

    while (hh != tt) {
        int t = q[hh++];
        if (hh == N) hh = 0;
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q[tt++] = j;
                    if (tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    scanf("%d%d%d", &n, &m1, &m2);
    memset(h, -1, sizeof h);

    for (int i = 1; i < n; i++) add(i + 1, i, 0);
    while (m1--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a > b) swap(a, b);
        add(a, b, c);
    }
    while (m2--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a > b) swap(a, b);
        add(b, a, -c);
    }

    if (spfa(n))
        puts("-1");
    else {
        spfa(1);
        if (dist[n] == INF)
            puts("-2");
        else
            printf("%d\n", dist[n]);
    }

    return 0;
}
