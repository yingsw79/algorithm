#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    int check(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, multiset<int>> mp;  //哈希表套平衡树
        for (auto& num : nums) {
            mp[check(num)].insert(num);
        }
        int res = INT_MIN;
        for (auto& [x, y] : mp) {
            if (y.size() > 1) {
                auto it = y.rbegin();
                int a = *it;
                ++it;
                int b = *it;
                res = max(res, a + b);
            }
        }
        return res == INT_MIN ? -1 : res;
    }
};

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int res = -1;
        unordered_map<int, int> hash;
        for (auto& x : nums) {
            int s = 0, y = x;
            while (y) s += y % 10, y /= 10;
            if (hash.count(s)) res = max(res, x + hash[s]);
            hash[s] = max(hash[s], x);
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}