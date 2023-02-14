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
    for(int _ = 1; _ <= 5; _++){
        startTest(_);
        int n,m;
        cnt = 0;
        memset(head,-1,sizeof head);
        cout << (n = rnd.next(1,100)) << " " << rnd.next(1,100) <<endl;
        int root = rnd.next(1,n);
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 1; i <= n - 1; i++){
            int x,y,w;
            x = rnd.next(1,n);
            y = rnd.next(1,n);
            while(find(x) == find(y)){
                x = rnd.next(1,n);
                y = rnd.next(1,n);
            }
            fa[find(x)] = find(y);
            add(x,y);
            add(y,x);
        }

        for(int i = 1; i<= n; i++){
            w[i] = rnd.next(1,4);
            v[i] = rnd.next(1,4);
        }

        dfs(root,-1);

        for(int i = 1; i <= n; i++){
            if(i == root){
                cout << v[i] << " " <<w[i] << " " << -1 << endl;
            }else{
                cout << v[i] << " " << w[i] << " " << dd[i] << endl;
            }
        }

    }





    return 0;
}
