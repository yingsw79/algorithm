#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/245/

const int N = 100010;
int a[N], res[N];
int tr[N];
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

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) tr[i] = lowbit(i);  //定义:覆盖的区间长度

    for (int i = n; i; i--) {
        int l = 1, r = n;
        int t = a[i] + 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (getsum(mid) >= t)
                r = mid;
            else
                l = mid + 1;
        }
        res[i] = l;
        add(l, -1);
    }

    for (int i = 1; i <= n; i++) printf("%d\n", res[i]);

    return 0;
}