#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/stock-price-fluctuation/?envType=daily-question&envId=2023-10-08

class StockPrice {
    multiset<int> ms;
    unordered_map<int, int> mp;
    int current_time = 0;

public:
    void update(int timestamp, int price) {
        if (mp.count(timestamp)) {
            ms.erase(ms.find(mp[timestamp]));
        }
        if (timestamp > current_time) {
            current_time = timestamp;
        }
        mp[timestamp] = price;
        ms.insert(price);
    }
    int current() { return mp[current_time]; }
    int maximum() { return *ms.rbegin(); }
    int minimum() { return *ms.begin(); }
};

int main() {
    return 0;
}