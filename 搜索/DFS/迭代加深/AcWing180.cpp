#include <bits/stdc++.h>
using namespace std;

// https://www.acwing.com/problem/content/description/182/

const int N = 20;
int a[N], n;

int h() {
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i)
        if (a[i + 1] != a[i] + 1) cnt++;
    return (cnt + 2) / 3;
}

bool dfs(int depth) {
    if (!depth) return h() == 0;
    if (h() > depth) return false;
    int c[N];
    memcpy(c, a, sizeof a);
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            for (int k = j + 1; k < n; ++k) {
                int p = i;
                for (int u = j + 1; u <= k; ++u) a[p++] = c[u];
                for (int u = i; u <= j; ++u) a[p++] = c[u];
                if (dfs(depth - 1)) return true;
                memcpy(a, c, sizeof a);
            }
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int depth = 0;
        while (depth < 5 && !dfs(depth)) depth++;
        if (depth < 5)
            printf("%d\n", depth);
        else
            puts("5 or more");
    }

    return 0;
}