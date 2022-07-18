#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << 10, K = 110;

int n, m;
vector<int> state;
int cnt[M];
vector<int> head[M];
LL f[N][K][M];

bool check(int state) { return !(state & state >> 1); }

int count(int state) {
    int res = 0;
    for (int i = 0; i < n; i++) res += state >> i & 1;
    return res;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < 1 << n; i++)
        if (check(i)) {
            state.push_back(i);  //预处理出合法状态
            cnt[i] = count(i);   //合法状态中1的个数
        }

    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++) {
            int a = state[i], b = state[j];
            if ((a & b) == 0 && check(a | b))
                head[i].push_back(j);  //预处理每个合法状态的合法前驱
        }                              //这里实际存的是状态数组下标

    f[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j <= m; j++)
            for (int a = 0; a < state.size(); a++)
                for (int b : head[a]) {
                    int c = cnt[state[a]];
                    if (j >= c) f[i][j][a] += f[i - 1][j - c][b];  //第三维是状态数组下标（也可用实际状态表示）
                }

    cout << f[n + 1][m][0] << endl;  //技巧：多处理一行省去统计所有状态的解

    return 0;
}
