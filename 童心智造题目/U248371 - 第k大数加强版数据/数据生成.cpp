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
    for(int i = 1; i <= 1; i++){
        startTest(i);
        int x;
        cout << (x = rnd.next((long long)1,(long long)5e6)) << endl;
        for(int j = 1; j <= x; j++)
        cout << (rnd.next((long long)1,(long long)2e9)) << " ";
        cout << endl;
        cout << rnd.next((long long)1,(long long)x) << endl;

    }





    return 0;
}
