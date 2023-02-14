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
    for(int _ = 6; _ <= 10; _++){
        startTest(_);
        int x = rnd.next(1,50);
        int y =  rnd.next(1,5) * x;
        cout << y << " " << x  <<endl;


    }





    return 0;
}
