#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/total-cost-to-hire-k-workers/

class Solution {
public:
    typedef long long LL;
    typedef pair<int, int> PII;
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        set<PII> s1, s2;
        int l = candidates - 1, r = n - candidates;
        for (int i = 0; i <= l; ++i) s1.emplace(costs[i], i);
        for (int i = r; i < n; ++i) s2.emplace(costs[i], i);
        l++, r--;
        LL res = 0;
        while (k--) {
            if (s1.begin()->first <= s2.begin()->first) {
                res += s1.begin()->first;
                costs[s1.begin()->second] = -1;
                if (auto it = s2.find(*s1.begin()); it != s2.end()) {
                    s2.erase(it);
                    while (r >= 0 && costs[r] == -1) r--;
                    if (r >= 0) s2.emplace(costs[r], r--);
                }
                s1.erase(s1.begin());
                while (l < n && costs[l] == -1) l++;
                if (l < n) s1.emplace(costs[l], l++);
            } else {
                res += s2.begin()->first;
                costs[s2.begin()->second] = -1;
                if (auto it = s1.find(*s2.begin()); it != s1.end()) {
                    s1.erase(it);
                    while (l < n && costs[l] == -1) l++;
                    if (l < n) s1.emplace(costs[l], l++);
                }
                s2.erase(s2.begin());
                while (r >= 0 && costs[r] == -1) r--;
                if (r >= 0) s2.emplace(costs[r], r--);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}