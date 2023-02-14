#include<iostream>
#include<cstring>
#include<testlib.h>
#include<utility>
#define x first
#define y second
using namespace std;
const int maxn = 2e6 + 5;
typedef pair<int,int> PII;
int head[maxn],last[maxn * 2],cnt,to[maxn * 2];
void add(int a,int b){
    to[++cnt] = b;
    last[cnt] = head[a];
    head[a] = cnt;
}
bool st[maxn];
int anss;

int n,m;
int flag[maxn],sum,maxns,a[maxn];
PII dfs(int x,int pre,int maxn){
    int ans = 0;
    if(st[x]) ans++;
    maxn = max(maxn,a[x]);
    int maxn2 = 0;
    int GG = ans,GG2 = ans;
    for(int i = head[x]; i != -1; i = last[i]){
        int j = to[i];
        if(j == pre) continue;
        PII xx = dfs(j,x,0);
        if(GG < xx.x + ans){
            maxn2 = maxn;
            maxn = xx.y;
            GG2 = GG;
            GG = xx.x + ans;
        }else if(GG == xx.x + ans && maxn < xx.y){
            maxn2 = maxn;
            maxn = xx.y;
            GG2 = GG;
            GG = xx.x + ans;
        }else if(GG2 < xx.x + ans){
            GG2 = xx.x + ans;
            maxn2 = xx.y;
        }else if(GG2 == xx.x + ans && maxn2 < xx.y){
            maxn2 = xx.y;
        }
    }
    maxn = max(maxn,a[x]);
    if(GG + GG2 - 1 == m){
        maxns = max(maxns,max(maxn,maxn2));
    }
    return PII{GG,maxn};
}

int main(){
    for(int _ = 8; _<= 8; _++){
        endTest(_);
        cin >> n >> m;
        int x;
        maxns = -2e9;
        cnt = 0;
        memset(head,-1,sizeof head);
        memset(st,0,sizeof st);
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
        }

        memset(st,0,sizeof st);
        for(int i = 1; i <= m; i++){
            scanf("%d",&x);
            st[x] = 1;
        }

        for(int i = 1; i <= n - 1; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            add(x,y);
            add(y,x);
        }

        for(int i = 1; i <= n; i++){
            if(st[i]){
                dfs(i,0,0);
                break;
            }
        }

        if(maxns != -2000000000) printf("%d\n",maxns);
        else printf("0");
    }


    return 0;
}
