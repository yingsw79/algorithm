#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/4504/

const int N = 100010;
int a[N];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        if (++a[x] == 1) cnt++;
        if (cnt == n) {
            printf("1");
            for (int i = 1; i <= n; i++) {
                if (--a[i] == 0) cnt--;
            }
        } else
            printf("0");
    }

    return 0;
}