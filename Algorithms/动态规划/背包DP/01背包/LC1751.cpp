#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended-ii/

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

// https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended-ii/solution/zui-duo-ke-yi-can-jia-de-hui-yi-shu-mu-i-jxj4/

class Solution2 {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const auto& e1, const auto& e2) {
            return e1[1] < e2[1];
        });

        int n = events.size();

        vector<pair<int, int>> curr;
        int ans = 0;

        for (int j = 1; j <= k; ++j) {
            vector<pair<int, int>> succ;
            for (int i = 0; i < n; ++i) {
                int fvalue;
                //返回第一个同时大于等于pair两个值元素的地址
                auto it = lower_bound(curr.begin(), curr.end(), pair{events[i][0], INT_MIN});
                if (it != curr.begin()) {
                    fvalue = prev(it)->second + events[i][2];
                } else {
                    fvalue = events[i][2];
                }
                ans = max(ans, fvalue);

                if (!succ.empty() && events[i][1] == succ.back().first && fvalue > succ.back().second) {
                    succ.pop_back();
                }
                if (succ.empty() || fvalue > succ.back().second) {
                    succ.emplace_back(events[i][1], fvalue);
                }
            }
            curr = succ;
        }

        return ans;
    }
};

int main() {
    system("pause");
    return 0;
}