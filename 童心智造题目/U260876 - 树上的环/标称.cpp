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

int c[maxn];
int a,b,st = 0;
void dfs(int x,int pre){
    if(x == b){
        st = 1;
        c[++anss] = x;
        return;
    }
    if(st){
        c[++anss] = x;
        return;
    }
    for(int i = head[x]; i != -1; i = last[i]){
        int j = to[i];
        if(j == pre) continue;
        dfs(j,x);
        if(st){
            c[++anss] = x;
            return;
        }
    }
}


int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n;
        cin >> n;
        memset(head,-1,sizeof head);
        cnt = 0;
        anss = 0;
        st = 0;
        for(int i = 1; i <= n - 1; i++){
            int x,y;

            cin >> x >>y;
            add(x,y);
            add(y,x);
        }
        cin >> a >> b;
        dfs(a,0);
        sort(c + 1,c + anss + 1);
        for(int i = 1; i <= anss ;i++){
            cout << c[i] << " ";
        }

    }
    return 0;
}
