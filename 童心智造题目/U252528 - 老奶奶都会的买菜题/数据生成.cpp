#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;


int fa[110];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

const int N = 11100,M = N;
int head[N],to[M],last[M],cnt,w[M];
void add(int a,int b){
    to[++cnt] = b;
    last[cnt] = head[a];
    head[a] = cnt;
}

int dd[N],v[M];
void dfs(int x,int y){
    for(int i = head[x]; i != -1; i = last[i]){
        int j = to[i];
        if(j == y) continue;
        dfs(j,x);
        dd[j] = x;
    }

}

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);
    int a[10];
    for(int _ = 6; _ <= 10; _++){
        startTest(_);
        int n;
        cout << (n = rnd.next(1,1000)) << " " << rnd.next(1,1000000) << endl;
        for(int i = 1; i <= n; i++){
            cout << rnd.next(1,100) * 100 << " " << rnd.next(1,1000000) << endl;
        }

    }





    return 0;
}
