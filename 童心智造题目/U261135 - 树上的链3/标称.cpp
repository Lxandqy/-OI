#include <bits/stdc++.h>
#include <testlib.h>
const int maxn = 3e6 + 5;
long long n, m, p;
using namespace std;

struct node {
    int idx, w;
    bool friend operator<(node a, node b) {
        return a.w < b.w;
    }
}q[maxn];

vector<int>v[maxn];

int a[maxn];

int pre[maxn];

int findf(int x) {
    return x == pre[x] ? x : pre[x] = findf(pre[x]);
}

int main() {
  //  freopen("./text/a.txt", "r", stdin);
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        cin >> n;
        for (int i = 0; i <= n; i++) pre[i] = i,v[i].clear();
        for (int i = 1; i <= n - 1; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            a[i] = x;
            q[i] = node{i, x};
        }
        sort(q+1, q+1+n);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int k = i;
            unordered_map<int, int>mp;
            while (k <= n && q[i].w == q[k].w) {
                for (int e: v[q[k].idx]) {
                    if (a[e] <= q[k].w) {
                        int dx = findf(e), dy = findf(q[k].idx);
                        if (dx != dy) {
                            pre[dx] = dy;
                        }
                    }
                }
                k++;
            }
            k = i;
            while (k <= n && q[i].w == q[k].w) {
                mp[findf(q[k].idx)]++;
                k++;
            }
            for (auto x: mp) {
                ans += 1ll * x.second * (x.second - 1) / 2;
            }
            i = k - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
