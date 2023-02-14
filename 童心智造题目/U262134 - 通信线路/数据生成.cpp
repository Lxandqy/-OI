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
    for(int _ = 4; _ <= 5; _++){
        startTest(_);
        int n,m;

        cout << (n = 1000) << " " << (m = n - 1) << " " << rnd.next(0,1000) << endl;
        for(int i = 1; i <= n; i++) mp[i].clear();


        for(int i = 1; i <= m; i++){
            cout <<i << " " << i + 1<< " " << rnd.next(1,1000000)<< endl;

        }

    }


    return 0;
}
