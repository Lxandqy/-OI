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
        int t;
        cout << (t = rnd.next(1,10)) << endl;
        for(int i = 1; i <= t; i++){
            int n;
            cout << (n = rnd.next(1,100000)) << endl;
            for(int i = 1; i <= n; i++){
                cout << rnd.next(1,1000000) << " ";
            }
        }
    }


    return 0;
}
