#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

class Solution {
public:
    typedef long long LL;
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<LL> sum(n + 1);
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + nums[i - 1];
        deque<int> q;
        q.push_back(0);
        int res = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            while (q.size() && sum[i] - sum[q.front()] >= k) {
                res = min(res, i - q.front());
                q.pop_front();
            }
            while (q.size() && sum[i] <= sum[q.back()]) q.pop_back();
            q.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    

    return 0;
}