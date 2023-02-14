#include<iostream>
#include<algorithm>
#include<testlib.h>
#include<queue>
#define first x
#define second y
#include<iostream>
#include<utility>
#include<queue>
#include<cstring>
#include<algorithm>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,pair<int,int> > PII;

const int N = 5000 * 5000 + 10;

int A[N];

ll n,m,a,b,c,d,p;
ll g[10001][10001];
ll dis[10010];
int vis[10001];
void prim()
{
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    for(int j=1;j<=n + m;j++)
    {
        ll min_len=1e18,k;
        for(int i=1;i<=n + m;i++)
        {
            if(!vis[i]&&dis[i]<min_len)
            {
                min_len=dis[i];
                k=i;
            }
        }
        vis[k]=1;
        for(int i=1;i<=n + m;i++)
        {
            if(!vis[i]&&dis[i]>g[k][i])
                dis[i]=g[k][i];
        }
    }
}

int main(){

    for(int _ = 10; _<= 10; _++){
        endTest(_);
        scanf("%lld %lld %lld %lld %lld %lld %lld",&n,&m,&a,&b,&c,&d,&p);
        A[0] = a;
        memset(g,0x3f,sizeof g);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int k = (i - 1) * m + j;
                A[k] = ((1ll * A[k - 1] * A[k - 1] % p) * b % p + A[k - 1] * c % p + d) % p;
                g[i][j + n] = A[k];
                g[j + n][i] = A[k];
            }
        }
        prim();
        ll ans = 0;
        for(int i = 1; i <= n + m; i++) ans += dis[i];

        cout << ans << endl;

    }




    return 0;
}
