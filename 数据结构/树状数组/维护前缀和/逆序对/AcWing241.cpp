#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/243/

const int N = 200010;
int a[N], tr[N], lw[N], gt[N];
int n;

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int getsum(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += tr[i];
    return sum;
}

// O(n)建树
void init() {
    for (int i = 1; i <= n; ++i) {
        tr[i] += a[i];
        int j = i + lowbit(i);
        if (j <= n) tr[j] += tr[i];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        int x = a[i];  //对数值
        gt[i] = getsum(n) - getsum(x);
        lw[i] = getsum(x - 1);
        add(x, 1);
    }

    memset(tr, 0, sizeof tr);
    LL res1 = 0, res2 = 0;
    for (int i = n; i; i--) {
        int x = a[i];
        res1 += (LL)gt[i] * (getsum(n) - getsum(x));
        res2 += (LL)lw[i] * getsum(x - 1);
        add(x, 1);
    }

    printf("%lld %lld\n", res1, res2);

    return 0;
}