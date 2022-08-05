#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

// https://www.luogu.com.cn/problem/P2661

const int N = 200010;
int n, a[N], q[N], indeg[N];

void topsort() {
    int l = 0, r = -1;
    for (int i = 1; i <= n; i++) {
        if (!indeg[i]) q[++r] = i;
    }
    while (l <= r) {
        int t = q[l++];
        int j = a[t];
        if (--indeg[j] == 0) q[++r] = j;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        indeg[a[i]]++;
    }
    topsort();
    int res = INF;
    for (int i = 1; i <= n; i++) {
        if (indeg[i]) {
            indeg[i] = 0;
            int cnt = 1;
            for (int j = a[i]; j != i; j = a[j]) {
                indeg[j] = 0;
                cnt++;
            }
            res = min(res, cnt);
        }
    }
    printf("%d\n", res);
    return 0;
}