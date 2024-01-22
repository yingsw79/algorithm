#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/sliding-window-median/description/

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> l, r;
        vector<double> res;
        for (int i = 0; i < nums.size(); i++) {
            if (r.empty() || nums[i] >= *r.begin()) {
                r.insert(nums[i]);
            } else {
                l.insert(nums[i]);
            }

            if (i >= k) {
                if (nums[i - k] >= *r.begin()) {
                    r.erase(r.find(nums[i - k]));
                } else {
                    l.erase(l.find(nums[i - k]));
                }
            }

            while (l.size() > r.size()) {
                r.insert(*l.rbegin());
                l.erase(l.find(*l.rbegin()));
            }
            while (r.size() > l.size() + 1) {
                l.insert(*r.begin());
                r.erase(r.begin());
            }

            if (i >= k - 1) {
                if (r.size() > l.size()) {
                    res.push_back(*r.begin());
                } else {
                    res.push_back(((double)*l.rbegin() + *r.begin()) / 2);
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}