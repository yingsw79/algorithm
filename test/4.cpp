#include <bits/stdc++.h>
using namespace std;
struct Node {
    int l, r;
    long long sum;
    bool friend operator<(const Node& x, const Node& y) { return x.sum < y.sum; }
};
priority_queue<Node> q;
long long a[100005], sum = 0;
Node make_Node(int l, int r, long long sum) {
    Node x;
    x.l = l, x.r = r, x.sum = sum;
    return x;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        q.push(make_Node(1, i, sum));
    }
    for (int i = 1; i <= k; ++i) {
        Node x;
        x = q.top();
        q.pop();
        printf("%lld ", x.sum);
        q.push(make_Node(x.l + 1, x.r, x.sum - a[x.l]));
    }
    printf("\n");
    return 0;
}