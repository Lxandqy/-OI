#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;


int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a[10];
    for(int _ = 5; _ <= 10; _++){
        startTest(_);
        int x;
        cout << (x = rnd.next(10,1000)) << " " << rnd.next(1000,1000) << endl;

        for(int i = 1; i <= x; i++){
            cout << rnd.next(1,1000) << " " << rnd.next(1,1000) << endl;
        }


    }





    return 0;
}
