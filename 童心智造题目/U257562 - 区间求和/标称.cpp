#include<bits/stdc++.h>
#include<testlib.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
int a[maxn],b[maxn],c[maxn],d[maxn],e[4 * maxn],s[4 * maxn];
int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n,m;
        int h = 0;
        memset(s,0,sizeof s);
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
            a[i] += 1e9;
            e[++h] = a[i];
        }
        for(int i = 1; i <= m; i++){
            cin >> c[i] >> d[i];
            c[i] += 1e9,d[i] += 1e9;
            e[++h] = c[i];
            e[++h] = d[i];
        }
        sort(e + 1,e + h + 1);
        int cnt = unique(e + 1,e + h + 1) - e - 1;
        for(int i = 1; i <= n; i++){
            a[i] = lower_bound(e + 1,e + cnt + 1,a[i]) - e;
            s[a[i]] += b[i];
        }
        for(int i = 1; i <= m; i++){
            c[i] = lower_bound(e + 1,e + cnt + 1,c[i]) - e;
            d[i] = lower_bound(e + 1,e + cnt + 1,d[i]) - e;
        }
        for(int i = 1; i <= cnt; i++){
            s[i] += s[i - 1];
        }
        for(int i = 1; i <= m; i++){
            cout << s[d[i]] - s[c[i] - 1] << endl;
        }

    }




    return 0;
}
