#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)

using namespace std;


int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int a;long long b;
	float c;double d;char e;
    for(int i = 1; i <= 30; i++){
        startTest(i);
        cout << i + 64 << endl;

    }






    return 0;
}
