#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 2000010;

int n, m;
int p[N];
unordered_map<int, int> S;  //离散化

struct Query {
    int x, y, e;
} query[N];

int get(int x) {
    if (!S.count(x)) S[x] = ++n;
    return S[x];
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        n = 0;
        S.clear();
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            int x, y, e;
            scanf("%d%d%d", &x, &y, &e);
            query[i] = {get(x), get(y), e};
        }

        for (int i = 1; i <= n; i++) p[i] = i;

        // 合并所有相等约束条件
        for (int i = 0; i < m; i++)
            if (query[i].e == 1) {
                int pa = find(query[i].x), pb = find(query[i].y);
                p[pa] = pb;
            }

        // 检查所有不等条件
        bool has_conflict = false;
        for (int i = 0; i < m; i++)
            if (query[i].e == 0) {
                int pa = find(query[i].x), pb = find(query[i].y);
                if (pa == pb) {
                    has_conflict = true;
                    break;
                }
            }

        if (has_conflict)
            puts("NO");
        else
            puts("YES");
    }

    return 0;
}
