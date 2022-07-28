#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int N = 100010;
int a[N], b[N], n;
LL res;
struct E {
    int l, r;
    LL w;
} q[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        q[i] = {i - a[i], i + a[i], (LL)a[i] * b[i]};
    }

    sort(q + 1, q + n + 1,
         [](auto& a, auto& b) {  //按结束时间从小到大排序
             return a.r < b.r;
         });

    vector<PII> t;  //单调队列优化
    for (int i = 1; i <= n; i++) {  
        LL val;  //以q[i]结尾的最大值，类似LIS问题
        auto it = upper_bound(t.begin(), t.end(), pair{q[i].l, LLONG_MIN});

        if (it != t.begin()) {
            val = prev(it)->second + q[i].w;
        } else {
            val = q[i].w;
        }

        res = max(res, val);

        if (!t.empty() && q[i].r == t.back().first && val > t.back().second) {
            t.pop_back();
        }
        if (t.empty() || val > t.back().second) {
            t.emplace_back(q[i].r, val);
        }
    }

    cout << res << endl;

    system("pause");
    return 0;
}