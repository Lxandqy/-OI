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
        double x = rnd.next(-10000.00,10000.00);
        cout << x  <<endl;


    }





    return 0;
}
