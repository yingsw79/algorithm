#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/problem/P1280

const int N = 10010;
vector<int> st[N];
int dp[N];  //dp[i]为第i分钟起最大闲暇时间
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    while (k--) {
        int p, t;
        scanf("%d%d", &p, &t);
        st[p].push_back(t);
    }
    for (int i = n; i; i--) {
        int m = st[i].size();
        if (m) {
            for (int j = 0; j < m; j++) {
                dp[i] = max(dp[i], dp[i + st[i][j]]);
            }
        } else
            dp[i] = dp[i + 1] + 1;
    }
    printf("%d\n", dp[1]);
    system("pause");
    return 0;
}