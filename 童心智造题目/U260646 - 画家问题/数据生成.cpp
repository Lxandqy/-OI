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

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        int n;
        cout <<  (n = rnd.next(1,15)) <<endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int x = rnd.next(0,1);
                if(x == 0) cout << 'w';
                else cout << 'y';
            }
            cout << endl;
        }
    }


    return 0;
}
