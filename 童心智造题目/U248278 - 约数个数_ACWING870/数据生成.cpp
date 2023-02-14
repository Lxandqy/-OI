#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)

using namespace std;


int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a[10];
    for(int i = 1; i <= 10; i++){
        startTest(i);
        cout << 100 << endl;
        for(int j = 1; j <= 100; j++)
        cout << rnd.next((long long)1,(long long)2e9) << endl;

    }





    return 0;
}
