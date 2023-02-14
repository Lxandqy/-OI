#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 101000;
int fa[N],n,m,t;
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

int a[N];

map<int,int>mp[1010];
int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int maxn = 0;
    for(int _ = 1; _ <= 11; _++){
        startTest(_);
        memset(pe,0,sizeof pe);
        int n,m,x;

        cout << rnd.next(1ll,1000000000000000000) << " " << rnd.next(1ll,1000000000000000000)<< " " <<  rnd.next(1ll,1000000000000000000);
    }


    return 0;
}
