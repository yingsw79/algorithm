#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/description/800/

const int N = 1010;

int n, m, q;
int a[N][N], b[N][N];

int main() {
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);

    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        b[x1][y1] += c;
        b[x2 + 1][y1] -= c;
        b[x1][y2 + 1] -= c;
        b[x2 + 1][y2 + 1] += c;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  // 对差分数组求前缀和

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) printf("%d ", a[i][j] + b[i][j]);
        puts("");
    }

    return 0;
}
