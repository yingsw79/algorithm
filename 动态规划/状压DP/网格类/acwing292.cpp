#include <iostream>
#include <vector>

using namespace std;

const int N = 110, M = 1 << 10;
int n, m;
int g[N], cnt[M];
int f[2][M][M];
vector<int> state;
vector<int> head[M];

int main() {
    // input
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            g[i] += (c == 'H') << j;
        }
    //找出所有合法状态
    for (int st = 0; st < 1 << m; ++st)
        if (!(st & st >> 1 || st & st >> 2))
            state.push_back(st), cnt[st] = __builtin_popcount(st);
    //找出所有合法状态的合法转移
    for (int cur_st : state)
        for (int pre_st : state)
            if (!(cur_st & pre_st)) head[cur_st].push_back(pre_st);
    // dp
    for (int i = 1; i <= n; ++i)
        for (int st : state)
            if (!(g[i] & st))
                for (int p1 : head[st])
                    for (int p2 : head[p1])
                        if (!(st & p2))
                            f[i & 1][st][p1] =
                                max(f[i & 1][st][p1],
                                    f[i - 1 & 1][p1][p2] + cnt[st]);
    // Enumerate the final state
    int res = 0;
    for (int st : state)
        for (int pre : head[st]) res = max(res, f[n & 1][st][pre]);
    // output
    cout << res << endl;
    return 0;
}
