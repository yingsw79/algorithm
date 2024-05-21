#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-star-sum-of-a-graph/

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<priority_queue<int, vector<int>, greater<int>>> g(n);
        auto sum = vals;
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (vals[b] > 0) {
                g[a].push(vals[b]);
                sum[a] += vals[b];
                if (g[a].size() > k) {
                    sum[a] -= g[a].top();
                    g[a].pop();
                }
            }

            if (vals[a] > 0) {
                g[b].push(vals[a]);
                sum[b] += vals[a];
                if (g[b].size() > k) {
                    sum[b] -= g[b].top();
                    g[b].pop();
                }
            }
        }
        return *max_element(sum.begin(), sum.end());
    }
};

int main() {
    return 0;
}