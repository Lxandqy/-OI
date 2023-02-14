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
        int n = rnd.next(1,3),m = rnd.next(2,5);
        cout << n <<" " <<  m <<endl;
        for(int i = 1; i <= n; i++){
            int x = rnd.next(1,m);
            memset(fa,0,sizeof fa);
            for(int j = 1; j <= x; j++){
                int y = rnd.next(1,m);
                while(fa[y]){
                    y = rnd.next(1,m);
                }
                fa[y] = 1;
                cout << y << " ";
            }
            cout << endl;
        }
    }


    return 0;
}
