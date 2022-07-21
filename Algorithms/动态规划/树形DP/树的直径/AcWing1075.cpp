#include <cstdio>
#include <iostream>
using namespace std;
const int N = 50005;
int n, ans = 0, s[N], f[N];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)  //求1~n每个数的约数之和（倍数法）O(nlogn)
        for (int j = i * 2; j <= n; j += i)
            s[j] += i;

    for (int i = n; i >= 2; i--) {
        if (s[i] >= i) continue;
        ans = max(ans, f[s[i]] + f[i] + 1);
        f[s[i]] = max(f[s[i]], f[i] + 1);
    }
    printf("%d\n", ans);
    return 0;
}
