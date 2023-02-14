#include<iostream>
#include<cstring>
#include<testlib.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int head[maxn],w[maxn * 2],last[maxn * 2],cnt;
void add(int x,int y){
    w[++cnt] = y;
    last[cnt] = head[x];
    head[x] = cnt;
}
bool st[maxn];
int anss;
int dfs(int x){
    st[x] = true;
    int sum = 1;
    int res = 0;
    for(int i = head[x]; i != -1; i = last[i]){
        if(!st[w[i]]){
            int s = dfs(w[i]);
            res = max(s,res);
            sum += s;
        }
    }
    anss = min(anss,max(n - sum,res));
    return sum;
}
int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        cin >> n;
        int x,y;
        memset(st,false,sizeof st);
        memset(head,-1,sizeof head);
        cnt = 0;
        anss = maxn;
        for(int i = 1; i <= n - 1; i++){
            cin >> x >> y;
            add(x,y),add(y,x);
        }
        dfs(1);
        cout << anss << endl;
    }
    return 0;
}
