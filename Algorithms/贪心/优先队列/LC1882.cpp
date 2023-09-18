#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/process-tasks-using-servers/

class Solution {
public:
    typedef pair<int, int> PII;               // 权重,编号
    typedef tuple<long long, int, int> TLII;  // 结束时间,权重,编号
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<PII, vector<PII>, greater<PII>> q1;
        priority_queue<TLII, vector<TLII>, greater<TLII>> q2;
        int n = servers.size(), m = tasks.size();
        vector<int> res(m);
        for (int i = 0; i < n; ++i) q1.emplace(servers[i], i);
        for (int i = 0; i < m; ++i) {
            while (q2.size() && get<0>(q2.top()) <= i) {
                q1.emplace(get<1>(q2.top()), get<2>(q2.top()));
                q2.pop();
            }
            if (q1.size()) {
                auto [w, idx] = q1.top();
                q1.pop();
                res[i] = idx;
                q2.emplace(i + tasks[i], w, idx);
            } else {
                auto [t, w, idx] = q2.top();
                q2.pop();
                res[i] = idx;
                q2.emplace(t + tasks[i], w, idx);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}