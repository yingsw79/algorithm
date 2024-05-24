#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/1244/

const int N = 1000010;
int p[N], n;  // p[i]第 i 个元素右边第一个未被染色的端点

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < N; i++) p[i] = i;

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        x = find(x);  // 从右边第一个未被染色的点开始染色
        printf("%d ", x);
        p[x] = find(x + 1);  // 标记已染色
    }

    return 0;
}