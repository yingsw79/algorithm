#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/most-popular-video-creator/

class Solution {
public:
    typedef long long LL;
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        unordered_map<string, LL> sum;
        LL mx = -1;
        for (int i = 0; i < n; ++i) {
            sum[creators[i]] += views[i];
            mx = max(mx, sum[creators[i]]);
        }
        unordered_map<string, set<pair<int, string>>> mp;
        for (int i = 0; i < n; ++i) {
            if (sum[creators[i]] == mx) mp[creators[i]].emplace(-views[i], ids[i]);
        }
        vector<vector<string>> res;
        for (auto& [x, y] : mp) res.push_back({x, y.begin()->second});
        return res;
    }
};

int main() {
    return 0;
}