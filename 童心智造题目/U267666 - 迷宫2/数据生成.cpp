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


map<int,int>mp[1000];
int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int maxn = 0;
    for(int _ = 4; _ <= 4; _++){
        startTest(_);
        memset(pe,0,sizeof pe);
        for(int i = 1; i <= 999; i++)
        mp[i].clear();
        cout << (n = rnd.next(1,5)) << " " << (m = rnd.next(1,5)) << " " << (t = 0) <<endl;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m - 1; j++){
                cout << rnd.next(1,10) << " ";
            }
            cout << endl;
        }
        for(int i = 1; i <= n - 1; i++){
            for(int j = 1; j <= m; j++){
                cout << rnd.next(1,10) << " ";
            }
            cout << endl;
        }

        for(int i = 1; i <= t; i++){
            int x = rnd.next(1,n),y = rnd.next(1,m);
            while(mp[x][y]){
                x = rnd.next(1,n),y = rnd.next(1,m);
            }
            mp[x][y] = 1;
            cout << x << " "<< y << endl;
        }

    }


    return 0;
}
