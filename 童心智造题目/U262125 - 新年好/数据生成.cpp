#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 1000010;

int fa[N];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

map<int,int>mp[N];

int dd[N];

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        int n,m;

        cout << (n = rnd.next(1,50000)) << " " << (m = rnd.next(n - 1,100000)) << endl;
        for(int i = 1; i <= n; i++) mp[i].clear();
        memset(fa,0,sizeof fa);
        for(int i = 1; i <= 5; i++){
            int x = rnd.next(1,n);
            while(fa[x]){
                fa[x] = 1;
                x = rnd.next(1,n);
            }
            fa[x] = 1;
            cout << x << " ";
        }
        cout << endl;

        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 1; i <= n - 1; i++){
             int x,y;
            x = rnd.next(1,n);
            y = rnd.next(1,n);
            while(find(x) == find(y)){
                x = rnd.next(1,n);
                y = rnd.next(1,n);
            }
            fa[find(x)] = find(y);
            mp[x][y] = mp[y][x] = 1;
            cout << x << " " << y << " " << rnd.next(1,100) << endl;
        }

        for(int i = n; i <= m; i++){
            int x,y;
            x = rnd.next(1,n);
            y = rnd.next(1,n);
            while(mp[x][y]){
                x = rnd.next(1,n);
                y = rnd.next(1,n);
            }
            mp[x][y] = mp[y][x] = 1;
            cout << x << " " << y << " " << rnd.next(1,100) << endl;
        }
    }


    return 0;
}
