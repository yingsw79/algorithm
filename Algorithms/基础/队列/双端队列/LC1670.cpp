#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/design-front-middle-back-queue/description/?envType=daily-question&envId=2023-11-28
// https://leetcode.cn/problems/find-median-from-data-stream/description/

class FrontMiddleBackQueue {
    deque<int> l, r;

public:
    void balance() {
        if (l.size() > r.size()) {
            r.push_front(l.back());
            l.pop_back();
        } else if (r.size() > l.size() + 1) {
            l.push_back(r.front());
            r.pop_front();
        }
    }

    void pushFront(int val) {
        l.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (l.size() < r.size()) {
            l.push_back(val);
        } else {
            r.push_front(val);
        }
    }

    void pushBack(int val) {
        r.push_back(val);
        balance();
    }

    int popFront() {
        if (r.empty()) {
            return -1;
        }
        int res;
        if (l.empty()) {
            res = r.front();
            r.pop_front();
        } else {
            res = l.front();
            l.pop_front();
        }
        balance();
        return res;
    }

    int popMiddle() {
        if (r.empty()) {
            return -1;
        }
        int res;
        if (l.size() == r.size()) {
            res = l.back();
            l.pop_back();
        } else {
            res = r.front();
            r.pop_front();
        }
        return res;
    }

    int popBack() {
        if (r.empty()) {
            return -1;
        }
        int res = r.back();
        r.pop_back();
        balance();
        return res;
    }
};

int main() {
    return 0;
}