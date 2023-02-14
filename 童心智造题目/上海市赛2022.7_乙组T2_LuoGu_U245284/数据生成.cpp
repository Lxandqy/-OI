#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)

using namespace std;

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);


    for(int _ = 1; _ <= 3; _++){
        startTest(_);
        int n;
        cout << (n = rnd.next(1,10)) << " " << rnd.next(0,100) << endl;
        for(int i = 1; i <= n; i++){
            cout << rnd.next(1,10000000) << " ";
        }
    }






    return 0;
}
