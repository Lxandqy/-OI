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
            printf("%d ",rnd.next(-1000000000,1000000000));
            printf("%lld ",rnd.next(-1000000000000000000,1000000000000000000));
            printf("%f ",rnd.next(-1000.0,1000.0));
            printf("%lf ",rnd.next(-10000000.0,10000000.0));
            printf("%c",char(rnd.next(0,25) + 'a'));

    }






    return 0;
}
