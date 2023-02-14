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
    for(int i = 1; i <= 10; i++){
        startTest(i);
        a = rnd.next(-10000000,10000000);
        b = rnd.next(-1000000000000000000,1000000000000000000);
        c = rnd.next(0.0,100000.00);
        d = rnd.next(-100000.565645646,1000000.1544455665);
        e = char('a' + rnd.next(0,25));

        cout <<a << " " << b << " " <<c << " " <<d << " " <<e << endl;

    }






    return 0;
}
