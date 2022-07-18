#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 14, M = 1 << 12, MOD = 1e8;

int n, m;
int w[N];
vector<int> state;
vector<int> head[M];
int f[2][M];


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            w[i] |= !t << j;  //把矩阵每一层的状态也用二进制来压缩存储
        }

    for (int i = 0; i < 1 << m; i++)
        if (!(i & i << 1)) state.push_back(i);

    for (auto& st1 : state)
        for (auto& st2 : state) {
            if (!(st1 & st2)) head[st1].push_back(st2);
        }

    f[0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (auto& cur : state) {
            f[i & 1][cur] = 0;  //要先置零
            if (!(cur & w[i]))
                for (auto& pre : head[cur])
                    f[i & 1][cur] = (f[i & 1][cur] + f[i - 1 & 1][pre]) % MOD;  //滚动数组优化
        }

    cout << f[n + 1 & 1][0] << endl;

    return 0;
}
