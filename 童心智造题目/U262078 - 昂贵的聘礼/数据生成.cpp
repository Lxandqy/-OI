#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 10000010;

int fa[N];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int dd[N];

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        int n = rnd.next(1,100),m = rnd.next(1,n);
        cout << m <<" " <<  n <<endl;

        for(int i = 1; i <= n; i++){
            int p,l,x;
            memset(fa,0,sizeof fa);
            cout << (p = rnd.next(1,10000)) << " " << (l = rnd.next(1,m)) << " " << (x = rnd.next(0,m - 1)) << endl;
            for(int j = 1; j <= x; j++){
                int y = rnd.next(1,n - 1);
                while(fa[y]){
                    y = rnd.next(1, n - 1);
                }
                fa[y] = 1;
                cout << y << " " << rnd.next(1,10000) << endl;
            }
        }

    }


    return 0;
}
