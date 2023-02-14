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
    for(int _ = 1; _ <= 20; _++){
        endTest(_);
        int n;
        cin >>n;
        long long sum = 0;
        for(int i = 1; i <= n; i++){
            long long ans = 1;
            for(int j = 1; j <= i; j++){
                ans = ans * j;
            }
            sum += ans;
        }
        cout << sum << endl;
    }
    return 0;
}
