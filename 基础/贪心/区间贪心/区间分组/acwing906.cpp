#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 100010;
PII q[N];
priority_queue<int, vector<int>, greater<int>> pq;

// https://leetcode.cn/problems/divide-intervals-into-minimum-number-of-groups/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });
        for (auto& q : intervals) {
            if (pq.size() && q[0] > pq.top()) pq.pop();
            pq.push(q[1]);
        }
        return pq.size();
    }
};

// 差分:
// 区间如果有重叠我们将其分开，枚举所有的区间组，最高的重叠次数就是答案。
// 从前往后枚举，用差分数组记录对应每个区间的计数，最后通过前缀和计算所有区间的最大计数即可
class Solution {
public:
    const int N = 1e6 + 10;
    int minGroups(vector<vector<int>>& inter) {
        int n = inter.size();
        vector<int> diff(N);
        for (auto& e : inter) {
            int l = e[0];
            int r = e[1];
            diff[l]++;
            diff[r + 1]--;
        }
        int now = diff[0];
        int ans = now;
        for (int i = 1; i < N; ++i) {
            now += diff[i];
            ans = max(ans, now);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {l, r};
    }
    sort(q, q + n);
    for (int i = 0; i < n; i++) {
        auto [l, r] = q[i];
        if (pq.empty() || pq.top() >= l)
            pq.push(r);
        else
            pq.pop(), pq.push(r);
    }
    cout << (int)pq.size() << endl;

    return 0;
}