#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 1010;

int b[N][N];
int fa[N],n;
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int pe[N];
void dfs(int x,int pre){
    pe[x] = pre;
    for(int i= 1; i <= n; i++){
        if(i == pre) continue;
        if(b[x][i]){
            dfs(i,x);
        }
    }
}

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        memset(b,0,sizeof b);
        memset(pe,0,sizeof pe);
        cout << (n = rnd.next(1,1000)) <<endl;
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 1; i <= n - 1; i++){
            int x = rnd.next(1,n),y = rnd.next(1,n);
            while(find(x) == find(y)){
                x = rnd.next(1,n),y = rnd.next(1,n);
            }
            fa[find(x)] = find(y);
            b[x][y] = 1;
            b[y][x] = 1;
        }
        int s = rnd.next(1,n);
        dfs(s,0);

        for(int i = 1; i <= n; i++){
            if(i == s) continue;
            cout << i << " " << pe[i] << endl;
        }
    }


    return 0;
}
