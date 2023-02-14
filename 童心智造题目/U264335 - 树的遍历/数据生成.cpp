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
        cout << (n = rnd.next(1,1000)) <<endl;
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 1; i <= n - 1; i++){
            int x = rnd.next(1,n),y = rnd.next(1,n);
            while(find(x) == find(y)){
                x = rnd.next(1,n),y = rnd.next(1,n);
            }
            fa[find(x)] = find(y);
            cout << x << " " <<y << endl;
        }
    }


    return 0;
}
