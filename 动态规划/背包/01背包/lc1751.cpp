#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended-ii/
// https://leetcode.cn/problems/maximum-profit-in-job-scheduling/
// https://leetcode.cn/problems/maximum-earnings-from-taxi/

class Solution1 {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const auto& e1, const auto& e2) {
            return e1[1] < e2[1];
        });
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= n; i++) {
            int target = events[i - 1][0];
            int l = -1, r = i - 2;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (events[mid][1] < target)
                    l = mid;
                else
                    r = mid - 1;
            }
            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[l + 1][j - 1] + events[i - 1][2]);
            }
        }
        return dp[n][k];
    }
};

int main() {
    system("pause");
    return 0;
}