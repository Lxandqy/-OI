#include<iostream>
#include<cstring>
#include<algorithm>
#include<testlib.h>
using namespace std;
const int maxn = 1e6 + 5;
int n;
int head[maxn],to[maxn * 2],w[maxn * 2],last[maxn * 2],cnt;
void add(int x,int y){
    to[++cnt] = y;
    last[cnt] = head[x];
    head[x] = cnt;
}
int anss;

int c[maxn],a[maxn],b[maxn];


int dfs(int x,int pre){
    int maxn = a[x];
    for(int i = head[x]; i != -1; i = last[i]){
        int j = to[i];
        if(j == pre) continue;
        maxn = max(dfs(j,x),maxn);
    }
    b[x] = maxn;
    return maxn;
}


int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n;
        cin >> n;
        memset(head,-1,sizeof head);
        cnt = 0;
        anss = 0;

        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
        }
        for(int i = 1; i <= n - 1; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            add(x,y);
            add(y,x);
        }

        dfs(1,0);

        for(int i = 1; i <= n; i++){
            cout << b[i] << " ";
        }


    }
    return 0;
}
