#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/minimum-money-required-before-transactions/

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        sort(transactions.begin(), transactions.end(), [](auto& a, auto& b) {
            int c = max(a[0], a[0] + b[0] - a[1]), d = max(b[0], a[0] + b[0] - b[1]);
            return c > d || c == d && a[0] > b[0];
        });
        long long res = 0, cost = 0;
        for (auto& t : transactions) {
            if (cost < t[0]) {
                res += t[0] - cost;
                cost = t[1];
            }
        }
        return res;
    }
};

class Solution {
public:
    typedef long long LL;
    long long minimumMoney(vector<vector<int>>& transactions) {
        LL sum = 0;
        for (auto& p : transactions) {
            int a = p[0], b = p[1];
            if (a > b) sum += a - b;
        }

        LL res = 0;
        for (auto& p : transactions) {
            int a = p[0], b = p[1];
            LL s = sum;
            if (a > b) s -= a - b;
            res = max(res, s + a);
        }

        return res;
    }
};
