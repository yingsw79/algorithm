#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/meeting-rooms-iii/
// https://leetcode.cn/problems/find-servers-that-handled-most-number-of-requests/

class Solution {
public:
    typedef pair<long long, int> PLI;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> q1;  // 空闲会议室
        priority_queue<PLI, vector<PLI>, greater<PLI>> q2;  // 被占用的会议室
        vector<int> cnt(n);
        for (int i = 0; i < n; ++i) q1.push(i);
        for (auto& m : meetings) {
            while (q2.size() && q2.top().first <= m[0]) {  // m[0]时刻恢复到空闲状态的会议室
                q1.push(q2.top().second);
                q2.pop();
            }
            if (q1.size()) {
                int t = q1.top();
                q1.pop();
                cnt[t]++;
                q2.emplace(m[1], t);
            } else {
                auto [x, y] = q2.top();
                q2.pop();
                cnt[y]++;
                q2.emplace(x + m[1] - m[0], y);
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
            if (cnt[res] < cnt[i]) res = i;
        return res;
    }
};

int main() {
    return 0;
}