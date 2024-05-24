#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2100;
const LL inf = 1e18;

// https://atcoder.jp/contests/abc264/tasks/abc264_f
// https://zhuanlan.zhihu.com/p/553510272

LL f[N][N][2][2];  //表示走到(i,j)这个格子,对r操作了0/1次,对c操作了0/1次的最小花费
int a[N][N];
int r[N], c[N];  //行和列的花费

int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++) scanf("%d", &r[i]);
    for (int i = 1; i <= w; i++) scanf("%d", &c[i]);

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            scanf("%1d", &a[i][j]);

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            for (int u = 0; u < 2; u++)
                for (int v = 0; v < 2; v++) f[i][j][u][v] = inf;

    f[1][1][0][0] = 0;
    f[1][1][1][0] = r[1];
    f[1][1][0][1] = c[1];
    f[1][1][1][1] = r[1] + c[1];

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            for (int u = 0; u < 2; u++) {  //对r操作
                for (int v = 0; v < 2; v++) {  //对c操作
                    if (i + 1 <= h) {
                        int co1 = a[i][j] ^ u ^ v;
                        int co2 = a[i + 1][j] ^ v;
                        //注意这里由于我们是往下走，那么我们只能翻转第i+1行,不能翻转第j列了
                        //因为我们路径上面的颜色都是已经确定相同了，如果我们对列操作，
                        //就会破坏路径上面已经相同的颜色
                        if (co1 == co2)
                            f[i + 1][j][0][v] = min(f[i + 1][j][0][v], f[i][j][u][v]);
                        else
                            f[i + 1][j][1][v] = min(f[i + 1][j][1][v], f[i][j][u][v] + r[i + 1]);
                    }
                    if (j + 1 <= w) {
                        int co1 = a[i][j] ^ u ^ v;
                        int co2 = a[i][j + 1] ^ u;
                        //和上面同理
                        if (co1 == co2)
                            f[i][j + 1][u][0] = min(f[i][j + 1][u][0], f[i][j][u][v]);
                        else
                            f[i][j + 1][u][1] = min(f[i][j + 1][u][1], f[i][j][u][v] + c[j + 1]);
                    }
                }
            }
        }
    }

    LL ans = inf;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            ans = min(ans, f[h][w][i][j]);

    cout << ans << endl;

    return 0;
}