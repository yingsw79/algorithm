#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/contest/tianchi2022/problems/ev2bru/
// https://leetcode.cn/problems/remove-duplicate-letters/

class Solution {
public:
    vector<int> arrangeBookshelf(vector<int>& order, int limit) {
        unordered_map<int, int> cnt, mp;
        for (int x : order) cnt[x]++;
        vector<int> res;
        for (int x : order) {
            if (mp[x] == limit) {
                cnt[x]--;
                continue;
            }
            while (res.size() && x < res.back() && cnt[res.back()] > limit) {
                cnt[res.back()]--;
                mp[res.back()]--;
                res.pop_back();
            }
            res.push_back(x);
            mp[x]++;
        }
        return res;
    }
};

// https://leetcode.cn/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for (auto x : num) {
            while (res.size() && k && x < res.back()) {
                res.pop_back();
                k--;
            }
            res.push_back(x);
        }
        while (k--) res.pop_back();
        int i = 0;
        while (i < res.length() && res[i] == '0') i++;
        res = res.substr(i);
        return res.empty() ? "0" : res;
    }
};

// https://leetcode.cn/problems/create-maximum-number/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> res(k, INT_MIN);
        for (int i = max(0, k - m); i <= min(k, n); i++) {
            auto a = maxArray(nums1, i);
            auto b = maxArray(nums2, k - i);
            auto c = merge(a, b);
            res = max(res, c);
        }
        return res;
    }

    vector<int> maxArray(vector<int>& nums, int k) {
        vector<int> res(k);
        int n = nums.size();
        for (int i = 0, j = 0; i < n; i++) {
            int x = nums[i];
            while (j && res[j - 1] < x && j + n - i > k) j--;
            if (j < k) res[j++] = x;
        }
        return res;
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> c;
        while (a.size() && b.size())
            if (a > b)
                c.push_back(a[0]), a.erase(a.begin());
            else
                c.push_back(b[0]), b.erase(b.begin());
        while (a.size()) c.push_back(a[0]), a.erase(a.begin());
        while (b.size()) c.push_back(b[0]), b.erase(b.begin());
        return c;
    }
};

int main() {
    return 0;
}