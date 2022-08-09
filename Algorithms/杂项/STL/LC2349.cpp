#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/design-a-number-container-system/submissions/

class NumberContainers {
    typedef pair<int, int> PII;
    unordered_map<int, int> mp;
    struct cmp {
        bool operator()(const PII& a, const PII& b) const {
            return a.first < b.first || a.first == b.first && a.second < b.second;
        }
    };
    multiset<PII, cmp> st;

public:
    void change(int index, int number) {
        if (mp.count(index)) st.erase({mp[index], index});
        st.emplace(number, index);
        mp[index] = number;
    }

    int find(int number) {
        auto it = st.lower_bound({number, INT_MIN});
        if (it == st.end() || it->first != number) return -1;
        return it->second;
    }
};

class NumberContainers {
    unordered_map<int, int> m;
    unordered_map<int, set<int>> ms;  //哈希表套平衡树

public:
    void change(int index, int number) {
        auto it = m.find(index);
        if (it != m.end()) {
            ms[it->second].erase(index);  // 移除旧数据
            it->second = number;          // 优化：直接在迭代器上赋值
        } else
            m[index] = number;
        ms[number].insert(index);  // 添加新数据
    }

    int find(int number) {
        auto it = ms.find(number);
        return it == ms.end() || it->second.empty() ? -1 : *it->second.begin();
    }
};

class NumberContainers {
    unordered_map<int, int> m;
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> ms;  //懒删除堆

public:
    void change(int index, int number) {
        m[index] = number;
        ms[number].push(index);  // 直接添加新数据，后面 find 再删除旧的
    }

    int find(int number) {
        auto it = ms.find(number);
        if (it == ms.end()) return -1;
        auto& q = it->second;
        while (!q.empty() && m[q.top()] != number) q.pop();
        return q.empty() ? -1 : q.top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main() {
    system("pause");
    return 0;
}