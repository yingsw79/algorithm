#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/combination-sum-iii/
// https://leetcode.cn/problems/the-number-of-beautiful-subsets/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        for (int i = 0; i < 1 << 9; i++) {
            if (__builtin_popcount(i) == k) {
                vector<int> tmp;
                int sum = 0;
                for (int j = 0; j < 9; j++) {
                    if (i >> j & 1) {
                        sum += j + 1;
                        if (sum > n) break;
                        tmp.push_back(j + 1);
                    }
                }
                if (sum == n) res.push_back(tmp);
            }
        }
        return res;
    }
};

// https://leetcode.cn/problems/combinations/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        for (int i = 0; i < 1 << n; i++) {
            if (__builtin_popcount(i) == k) {
                vector<int> tmp;
                for (int j = 0; j < n; j++) {
                    if (i >> j & 1) tmp.push_back(j + 1);
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}