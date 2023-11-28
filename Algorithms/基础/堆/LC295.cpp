#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/find-median-from-data-stream/description/
// https://leetcode.cn/problems/design-front-middle-back-queue/description/?envType=daily-question&envId=2023-11-28

class MedianFinder {
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

public:
    void balance() {
        if (l.size() > r.size()) {
            r.push(l.top());
            l.pop();
        } else if (r.size() > l.size() + 1) {
            l.push(r.top());
            r.pop();
        }
    }

    void addNum(int num) {
        if (r.empty() || num > r.top()) {
            r.push(num);
        } else {
            l.push(num);
        }
        balance();
    }

    double findMedian() {
        if (l.size() == r.size()) {
            return (l.top() + r.top()) / 2.0;
        }
        return r.top();
    }
};

int main() {
    return 0;
}