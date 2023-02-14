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
    for(int i = 1; i <= 5; i++){
        startTest(i);
        cout << rnd.next((long long)0,(long long)1e6) << " " << rnd.next((long long)0,(long long )1e6) << endl;

    }

    for(int i = 6; i <= 10; i++){
        startTest(i);
        cout << rnd.next((long long)0,(long long )1e6) << " " << rnd.next((long long)0,(long long )1e6)  << endl;

    }




    return 0;
}
