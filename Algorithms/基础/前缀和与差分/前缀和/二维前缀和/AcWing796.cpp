#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/798/

const int N = 1010;

int a[N][N], s[N][N];

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];  // 求前缀和
        }

    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        // 算子矩阵的和
        printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
    }

    return 0;
}
