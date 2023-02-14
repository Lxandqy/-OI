#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 100010;

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a,b,c,d,maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        int n,m;
        cout << (n = rnd.next(1,100000)) << " " << (m = rnd.next(1,100000)) << endl;
        for(int i = 1; i <= n; i++){
            cout << rnd.next(-1000000000,1000000000) << " " << rnd.next(-10000,10000) << endl;
        }
        int s ;
        for(int i = 1; i <= m; i++){
            cout << (s = rnd.next(-1000000000,1000000000)) << " " << rnd.next(s,1000000000) << endl;
        }
    }


    return 0;
}
