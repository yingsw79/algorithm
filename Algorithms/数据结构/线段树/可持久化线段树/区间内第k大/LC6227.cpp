#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/next-greater-element-iv/

class Solution {
    static const int N = 100010;
    int tot;
    struct Node {
        int ls, rs, cnt;
    } tr[N * 20];

    int insert(int p, int l, int r, int x) {
        int q = ++tot;
        tr[q] = tr[p];
        if (l == r) {
            ++tr[q].cnt;
            return q;
        }
        int mid = l + r >> 1;
        if (x <= mid)
            tr[q].ls = insert(tr[p].ls, l, mid, x);
        else
            tr[q].rs = insert(tr[p].rs, mid + 1, r, x);
        tr[q].cnt = tr[tr[q].ls].cnt + tr[tr[q].rs].cnt;
        return q;
    }

    int query(int p, int q, int l, int r, int x) {
        if (l == r) return tr[p].cnt - tr[q].cnt;
        int mid = l + r >> 1;
        if (x <= mid)
            return query(tr[p].ls, tr[q].ls, l, mid, x) + tr[tr[p].rs].cnt - tr[tr[q].rs].cnt;
        else
            return query(tr[p].rs, tr[q].rs, mid + 1, r, x);
    }

public:
    vector<int> secondGreaterElement(vector<int>& a) {
        tot = 0;
        int n = a.size();
        vector<int> res(n, -1), root(n + 1);
        auto nums = a;
        sort(nums.begin(), nums.end());
        int m = unique(nums.begin(), nums.end()) - nums.begin();
        for (int i = 1; i <= n; ++i)
            root[i] = insert(root[i - 1], 1, m, lower_bound(nums.begin(), nums.begin() + m, a[i - 1]) - nums.begin() + 1);
        for (int i = 1; i <= n; ++i) {
            int x = lower_bound(nums.begin(), nums.begin() + m, a[i - 1] + 1) - nums.begin() + 1;
            if (x > m) continue;
            int l = i, r = n + 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (query(root[mid], root[i], 1, m, x) >= 2)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (l != n + 1) res[i - 1] = a[l - 1];
        }
        return res;
    }
};

int main() {
    return 0;
}