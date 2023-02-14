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

    int a,b,c,d,maxn = 0;
    for(int _ = 1; _ <= 10; _++){
            maxn = 0;
        startTest(_);
        cout << rnd.next(1,5000) << " " <<rnd.next(1,5000) << " " << (a = rnd.next(1,99999)) << " " <<(b = rnd.next(1,99999)) << " " << (c = rnd.next(1,99999)) << " " << (d = rnd.next(1,99999));
        maxn = max(maxn,a);
        maxn = max(maxn,b);
        maxn = max(maxn,c);
        maxn = max(maxn,d);
        cout << " " <<rnd.next(maxn +1,100000);
    }





    return 0;
}
