#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 101000;
int fa[N],n;
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

vector<int>v[N];
int pe[N];
void dfs(int x,int pre){
    pe[x] = pre;
    for(int i= 0; i < v[x].size(); i++){
            int j = v[x][i];
        if(j == pre) continue;
            dfs(j,x);
    }
}



int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        memset(pe,0,sizeof pe);
        cout << (n = rnd.next(1,100000)) <<endl;
        for(int i = 1; i <= n; i++) fa[i] = i,v[i].clear();
        for(int i = 1; i <= n - 1; i++){
            int x = rnd.next(1,n),y = rnd.next(1,n);
            while(find(x) == find(y)){
                x = rnd.next(1,n),y = rnd.next(1,n);
            }
            fa[find(x)] = find(y);
            v[x].push_back(y);
            v[y].push_back(x);
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
