#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"
#define r(x,a,b) (x = rnd.next(a,b))

using namespace std;

const int N = 10000010;

int fa[N];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        int n,m;
        cout <<  (n = rnd.next(1,100000)) <<endl;
        for(int i = 1; i <= n; i++){
            cout << rnd.next(1,10000) <<" ";
        }
        cout <<  (m = rnd.next(1,100000)) <<endl;
        for(int i = 1; i <= m; i++){
            int x,y;
            cout << r(x,1,n) <<" "<< r(y,x,n) << " " << rnd.next(1,10000) << endl;
        }
        int x,y;
        cout << (x = rnd.next(1,n)) << " " << (rnd.next(x,n)) << endl;
    }


    return 0;
}
