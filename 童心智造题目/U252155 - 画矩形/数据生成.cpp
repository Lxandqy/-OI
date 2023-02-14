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
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        cout << rnd.next(3,10) << " " << rnd.next(3,10) << " " << (char)rnd.next(50,100) << " " << rnd.next(0,1) << endl;


    }





    return 0;
}
