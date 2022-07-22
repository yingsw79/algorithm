#pragma GCC optimize(3)
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x) {
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;  //编号必须从1开始，因为后面会用到前缀和
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});

        alls.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 处理插入
    for (auto& [x, y] : add) {
        int idx = find(x);
        a[idx] += y;
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];  //编号从1开始

    // 处理询问
    for (auto& [x, y] : query) {
        int l = find(x), r = find(y);
        cout << s[r] - s[l - 1] << endl;  //编号从1开始则l-1不会越界
    }

    return 0;
}
