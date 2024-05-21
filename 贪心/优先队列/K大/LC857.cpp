#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> q(n);
        for (int i = 0; i < n; ++i)
            q[i] = {(double)wage[i] / quality[i], quality[i]};
        sort(q.begin(), q.end());
        priority_queue<int> pq;
        double res = 1e18, sum = 0;
        for (auto& [x, y] : q) {
            sum += y;
            pq.push(y);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) res = min(res, sum * x);
        }
        return res;
    }
};

// https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        for (int x : arr) {
            res.push_back(x);
            push_heap(res.begin(), res.end());
            if (res.size() > k) {
                pop_heap(res.begin(), res.end());
                res.pop_back();
            }
        }
        return res;
    }
};

int main() {
    return 0;
}