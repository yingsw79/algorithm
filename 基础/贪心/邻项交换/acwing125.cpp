#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef pair<int, int> PII;
const int N = 50010;
PII cows[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, w, s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w >> s;
        cows[i] = {w, s};
    }

    sort(cows, cows + n, [](const PII& p1, const PII& p2) {
        return p1.first + p1.second < p2.first + p2.second;
    });

    int sum = 0, res = INT_MIN;
    for (int i = 0; i < n; i++) {
        res = max(res, sum - cows[i].second);
        sum += cows[i].first;
    }
    cout << res << endl;
    return 0;
}